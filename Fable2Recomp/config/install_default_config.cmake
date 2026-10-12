# Installs the shipped player settings beside the built game, once.
#
#   cmake -DSRC=<config/Fable2.default.toml> -DDST=<exe folder>/Fable2.toml -P install_default_config.cmake
#
# Run by the Fable2 target's POST_BUILD step (CMakeLists.txt). An existing DST (the player's or developer's own
# settings, also written by the F4 settings overlay) is never touched; delete it to get the defaults back.
cmake_minimum_required(VERSION 3.21)  # file(COPY_FILE)

if(NOT SRC OR NOT DST)
    message(FATAL_ERROR "install_default_config.cmake: pass -DSRC=<template> -DDST=<settings file>")
endif()
if(EXISTS "${DST}")
    return()
endif()
if(NOT EXISTS "${SRC}")
    message(WARNING "Fable2: default settings template not found: ${SRC} (no Fable2.toml installed)")
    return()
endif()
get_filename_component(_dst_dir "${DST}" DIRECTORY)
file(MAKE_DIRECTORY "${_dst_dir}")
file(COPY_FILE "${SRC}" "${DST}")
message(STATUS "Fable2: installed the default settings ${DST}")
