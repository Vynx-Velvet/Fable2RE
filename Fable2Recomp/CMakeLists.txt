# Fable2 - ReXGlue Recompiled Project
# Started from the file `rexglue migrate` generates; maintained by hand since (Fable2RE: native renderer, lifted
# code, mods, tools). Do not regenerate it with `rexglue migrate`, which would overwrite these changes.

cmake_minimum_required(VERSION 3.25)
project(Fable2 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(REXSDK_DIR "" CACHE PATH "Path to rexglue-sdk source tree")
if(REXSDK_DIR)
    add_subdirectory("${REXSDK_DIR}" rexglue-sdk)
else()
    find_package(rexglue QUIET CONFIG)
    if(NOT rexglue_FOUND)
        message(FATAL_ERROR
            "ReXGlue SDK not found. Either:\n"
            "  - Set REXSDK_DIR to the rexglue-sdk source tree (the repository's rexglue-sdk/; the presets read $env:REXSDK)\n"
            "  - Install the SDK package and ensure it is on CMAKE_PREFIX_PATH")
    endif()
endif()

# Third-party libraries
add_library(dlmalloc STATIC thirdparty/dlmalloc/dlmalloc.c)
target_include_directories(dlmalloc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/dlmalloc)
target_compile_definitions(dlmalloc PUBLIC
    MSPACES=1
    USE_LOCKS=1
    ONLY_MSPACES=1
    HAVE_MORECORE=0
    ABORT_ON_ASSERT_FAILURE=0
    USE_DL_PREFIX=1
    FOOTERS=0
)
if(MSVC)
    target_compile_options(dlmalloc PRIVATE /wd4244 /wd4267 /wd4146 /wd4996)
elseif(CMAKE_C_COMPILER_ID MATCHES "Clang")
    target_compile_options(dlmalloc PRIVATE -Wno-incompatible-pointer-types -Wno-deprecated-declarations)
endif()

# Sources
set(FABLE2_SOURCES
    src/main.cpp
    src/heap.cpp
    src/hooks.cpp
    src/sampler.cpp
    src/tracer.cpp
    src/hooks_audio_trace.cpp
    src/d3d_probe.cpp
    src/d3d_capture.cpp
    src/native_frontend.cpp
    src/gpu_sync.cpp
    src/thread_stats.cpp
    src/render_sampler.cpp
    src/lua_bridge.cpp
    src/debug_menu.cpp
    src/autotest.cpp
    src/modding/mod_loader.cpp
)

# Hand-written C++ replacing recompiled game functions (one folder per subsystem, see
# docs/conversion-guide.md); new files are picked up automatically.
# (also picks up the promoted modules in src/game/promoted/: rendered there from promoted/ with the text of the
# user's copy, tools/rewrite/promoted_text.py)
file(GLOB_RECURSE FABLE2_GAME_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/game/*.cpp)
list(APPEND FABLE2_SOURCES ${FABLE2_GAME_SOURCES})

# Lifted (readable) game code generated locally by tools/lift/lift.py; each function overrides the
# recompiled one (cvar lifted_code switches back).
file(GLOB FABLE2_LIFTED_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/lifted/lifted.*.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/lifted/native_bridges.*.cpp)
list(APPEND FABLE2_SOURCES ${FABLE2_LIFTED_SOURCES})

# Include generated code if codegen has been run
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/generated/sources.cmake")
    include(generated/sources.cmake)
    list(APPEND FABLE2_SOURCES ${GENERATED_SOURCES})
endif()
# Add cross-function label stubs if they exist
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/generated/Fable2_recomp_stubs.cpp")
    list(APPEND FABLE2_SOURCES generated/Fable2_recomp_stubs.cpp)
endif()

if(WIN32)
    add_executable(Fable2 WIN32 ${FABLE2_SOURCES})
else()
    add_executable(Fable2 ${FABLE2_SOURCES})
endif()

target_include_directories(Fable2 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/generated
    # Borrow the include directories (only) of the SDK object libraries whose
    # headers the host sources use: the generated rex/version.h (rexcore), the
    # overlay headers (rexui) and imgui.h. Never link those objects into the
    # host (see the link note below).
    $<TARGET_PROPERTY:rexcore,INTERFACE_INCLUDE_DIRECTORIES>
    $<TARGET_PROPERTY:rexui,INTERFACE_INCLUDE_DIRECTORIES>
    $<TARGET_PROPERTY:rexgraphics,INTERFACE_INCLUDE_DIRECTORIES>
    $<TARGET_PROPERTY:imgui,INTERFACE_INCLUDE_DIRECTORIES>
)

# Link ONLY the shared runtime. rex::core / rex::graphics / rex::ui are OBJECT
# libraries that are already compiled into rexruntime; linking them here as
# well gave Fable2.exe private copies of cvar.cpp, logging.cpp, the graphics
# system, etc. (two cvar registries, two logger registries: Fable2.toml could
# not reach cvars defined in DLL-only code such as mnk_mode, and DLL-side logs
# never reached fable2.log). rex::system / rex::kernel are aliases of
# rex::runtime, which exports all symbols (WINDOWS_EXPORT_ALL_SYMBOLS).
target_link_libraries(Fable2 PRIVATE
    rex::runtime
    dlmalloc
)

# Modding: MinHook (run-time replacement of recompiled functions by plugin DLLs) and the SDK headers
# shared by built-in modules and plugins (sdk/include/fable2).
add_library(minhook STATIC
    thirdparty/minhook/src/buffer.c
    thirdparty/minhook/src/hook.c
    thirdparty/minhook/src/trampoline.c
    thirdparty/minhook/src/hde/hde64.c
)
target_include_directories(minhook PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/minhook/include)
target_include_directories(Fable2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/sdk/include)
target_link_libraries(Fable2 PRIVATE minhook)

# Example native mod (plugin DLL): sdk/examples/hello_mod.
add_library(Fable2ExampleMod SHARED sdk/examples/hello_mod/hello_mod.cpp)
set_target_properties(Fable2ExampleMod PROPERTIES OUTPUT_NAME HelloMod)
target_include_directories(Fable2ExampleMod PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/sdk/include
    $<TARGET_PROPERTY:rexcore,INTERFACE_INCLUDE_DIRECTORIES>
)

# Platform entry point, ReXApp source, and platform-specific settings
rexglue_configure_target(Fable2)

# Player settings: install config/Fable2.default.toml as Fable2.toml beside the exe, only when that file does not
# exist yet (an existing Fable2.toml is never overwritten). Keys: docs/settings.md.
add_custom_command(TARGET Fable2 POST_BUILD
    COMMAND ${CMAKE_COMMAND}
        -DSRC=${CMAKE_CURRENT_SOURCE_DIR}/config/Fable2.default.toml
        -DDST=$<TARGET_FILE_DIR:Fable2>/Fable2.toml
        -P ${CMAKE_CURRENT_SOURCE_DIR}/config/install_default_config.cmake
    VERBATIM
)

# Codegen target - run 'cmake --build . --target Fable2_codegen'
add_custom_target(Fable2_codegen
    COMMAND $<TARGET_FILE:rex::rexglue> codegen ${CMAKE_CURRENT_SOURCE_DIR}/Fable2_config.toml
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Generating recompiled code for Fable2"
    VERBATIM
)

# Native D3D12 renderer (native/): driven at the Xbox D3D API level, no command stream parsing
# or EDRAM emulation. Used by the offline replayer and by the game (native_renderer=true).
add_library(Fable2Native STATIC
    native/guest_state.cpp
    native/texture_decode.cpp
    native/renderer.cpp
)
target_include_directories(Fable2Native PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/native
    $<TARGET_PROPERTY:rexcore,INTERFACE_INCLUDE_DIRECTORIES>
    $<TARGET_PROPERTY:rexui,INTERFACE_INCLUDE_DIRECTORIES>
    $<TARGET_PROPERTY:rexgraphics,INTERFACE_INCLUDE_DIRECTORIES>
)
target_link_libraries(Fable2Native PUBLIC rex::runtime d3d12 dxgi d3dcompiler)
target_link_libraries(Fable2 PRIVATE Fable2Native dbghelp winmm)

# Offline replayer for D3D frame captures (native renderer development, see replay/main.cpp).
add_executable(Fable2Replay replay/main.cpp replay/capture.cpp)
target_include_directories(Fable2Replay PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(Fable2Replay PRIVATE Fable2Native dbghelp winmm)
# Debug info for the native renderer / replayer (crash stacks under cdb).
target_compile_options(Fable2Native PRIVATE -g -gcodeview)
target_compile_options(Fable2Replay PRIVATE -g -gcodeview)
target_link_options(Fable2Replay PRIVATE -g -Wl,/DEBUG)
# Debug info for the game's native frontend and a PDB for Fable2.exe (crash dumps from the native
# renderer resolve to function names; the recompiled code itself is built without debug info).
set_source_files_properties(src/native_frontend.cpp PROPERTIES COMPILE_OPTIONS "-g;-gcodeview")
target_link_options(Fable2 PRIVATE -g -Wl,/DEBUG)
