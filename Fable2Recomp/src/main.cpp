#include "generated/Fable2_init.h"
#include "heap.h"
#include "debug_menu.h"
#include "modding/mod_loader.h"
#include "game/debug/debug_overlay.h"
#include <windows.h>
#include <timeapi.h>
void StartCpuSampler();
void StartThreadStats();
bool NativeGpuSync_Start();
void NativeGpuSync_Stop();
void StartIndirectTracer();
void D3DCapture_Request();
void NativeFrontend_RequestSnapshot();
void NativeFrontend_RequestBurst();
void NativeFrontend_RequestHistory();
void NativeFrontend_RequestInvalidate();
#include <rex/cvar.h>
#include <rex/filesystem.h>
#include <rex/logging.h>
#include <rex/logging/sink.h>
#include <rex/runtime.h>
#include <rex/kernel/init.h>
#include <rex/graphics/graphics_system.h>
#if REX_HAS_D3D12
#include <rex/graphics/d3d12/graphics_system.h>
#endif
#include <rex/audio/audio_system.h>
#include <rex/audio/sdl/sdl_audio_system.h>
#include <rex/input/input_system.h>
#include <rex/ui/immediate_drawer.h>
#include <rex/ui/imgui_drawer.h>
#include <rex/ui/overlay/debug_overlay.h>
#include <rex/ui/overlay/console_overlay.h>
#include <rex/ui/overlay/settings_overlay.h>
#include <rex/ui/window.h>
#include <rex/ui/window_listener.h>
#include <rex/ui/keybinds.h>
#include <rex/ui/windowed_app.h>
#include <rex/ui/window_win.h>
#include "autotest.h"
#include <atomic>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <thread>
#if defined(_WIN32)
#include <crtdbg.h>
#endif

REXCVAR_DEFINE_INT32(window_width, 1600, "UI/Window", "Initial window client width")
    .range(640, 7680);
REXCVAR_DEFINE_INT32(window_height, 900, "UI/Window", "Initial window client height")
    .range(360, 4320);

class Fable2App : public rex::ui::WindowedApp, public rex::ui::WindowListener, public rex::ui::WindowInputListener {
 public:
  static std::unique_ptr<rex::ui::WindowedApp> Create(rex::ui::WindowedAppContext& c) { return std::make_unique<Fable2App>(c); }
  Fable2App(rex::ui::WindowedAppContext& c) : WindowedApp(c, "Fable2", "[game_directory]") { AddPositionalOption("game_directory"); }
  bool OnInitialize() override {
#if defined(_WIN32)
    // Debug CRT: route abort()/assert reports to stderr instead of a modal
    // "Debug Error!" dialog that leaves a crashed run hanging until killed.
    _set_abort_behavior(0, _WRITE_ABORT_MSG | _CALL_REPORTFAULT);
    // assert() in a GUI app pops a modal "Assertion failed!" box that parks the
    // guest thread forever; send it to stderr instead.
    _set_error_mode(_OUT_TO_STDERR);
    _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
    _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
#endif
    auto exe_dir = rex::filesystem::GetExecutableFolder();
    std::filesystem::path assets_root;
    if (auto a = GetArgument("game_directory")) assets_root = *a; else assets_root = exe_dir / "assets";
    auto game_dir = assets_root / "game"; auto update_dir = assets_root / "update";
    // Load Fable2.toml next to the exe BEFORE reading any cvar (mirrors
    // ReXApp::OnInitialize). Without this every cvar keeps its compiled-in
    // default: log_level stays "info", mnk_mode stays off, etc.
    auto config_path = exe_dir / "Fable2.toml";
    if (std::filesystem::exists(config_path)) rex::cvar::LoadConfig(config_path);
    AutoTest_Init();  // src/autotest.cpp: unattended test runs (F2_AUTOTEST / F2_CVARS), no-op otherwise
    StartCpuSampler();  // src/sampler.cpp, no-op unless cpu_sampler_thread is set
    StartIndirectTracer();  // src/tracer.cpp, no-op unless trace_indirect_calls
    StartThreadStats();     // src/thread_stats.cpp: busiest threads every 5 s
    // Guest KeDelayExecutionThread/Sleep calls become host Sleep(ms); without a 1 ms
    // scheduler period a 1 ms sleep lasts up to 15.6 ms, which starves the render
    // thread's ring-buffer wait and the game thread's frame pacing.
    timeBeginPeriod(1);
    std::string lvl = REXCVAR_GET(log_level);
    if (REXCVAR_GET(log_verbose) && lvl == "info") lvl = "trace";
    std::string log_path = (exe_dir / "fable2.log").string();
    auto log_config = rex::BuildLogConfig(log_path.c_str(), lvl, rex::ParseCategoryLevelsFromConfig(config_path));
    rex::InitLogging(log_config);
    rex::RegisterLogLevelCallback();  // log_level cvar changes (settings overlay) take effect live
    log_sink_ = std::make_shared<rex::LogCaptureSink>();
    rex::AddSink(log_sink_);
    REXLOG_INFO("Fable2 starting");
    if (std::filesystem::exists(config_path)) REXLOG_INFO("Loaded config: {}", config_path.string());
    REXLOG_INFO("  cvars: log_level={} log_noisy={} mnk_mode={} input_backend={}", rex::cvar::GetFlagByName("log_level"),
                rex::cvar::Query<bool>("log_noisy"), rex::cvar::Query<bool>("mnk_mode"), rex::cvar::GetFlagByName("input_backend")); REXLOG_INFO("  Game directory: {}", game_dir.string()); REXLOG_INFO("  Update directory: {}", update_dir.string());
    // cache/ next to the exe holds the persistent D3D12 shader + pipeline
    // storage (see InitializeShaderStorage below); without it every run
    // recompiles every pipeline on first use, which shows up as hitches.
    auto cache_dir = exe_dir / "cache";
    std::error_code cache_ec;
    std::filesystem::create_directories(cache_dir, cache_ec);
    runtime_ = std::make_unique<rex::Runtime>(game_dir, game_dir, update_dir, cache_dir);
    runtime_->set_app_context(&app_context());
    rex::RuntimeConfig config;
#if REX_HAS_D3D12
    config.graphics = REX_GRAPHICS_BACKEND(rex::graphics::d3d12::D3D12GraphicsSystem);
#endif
    config.audio_factory = REX_AUDIO_BACKEND(rex::audio::sdl::SDLAudioSystem);
    config.input_factory = REX_INPUT_BACKEND(rex::input::CreateDefaultInputSystem);
    // Loads the xboxkrnl/xam/xbdm kernel modules and registers the XAM apps
    // (XMsg dispatch, XLiveBase, XGI, XMP). Without this the kernel module list
    // is empty and e.g. NetDll_XNetStartup's GetKernelModule("xam.xex") asserts.
    config.kernel_init = rex::kernel::InitializeKernel;
    rex::PPCImageInfo ii{static_cast<u32>(REX_CODE_BASE),static_cast<u32>(REX_CODE_SIZE),static_cast<u32>(REX_IMAGE_BASE),static_cast<u32>(REX_IMAGE_SIZE),PPCFuncMappings};
    // The emulated GPU command processor is only needed without the native renderer + native GPU
    // synchronisation (src/gpu_sync.cpp).
    if (!rex::cvar::Query<bool>("native_renderer") || !rex::cvar::Query<bool>("native_gpu_sync"))
      rex::cvar::SetFlagByName("gpu_command_processor", "true");
    auto s = runtime_->Setup(ii, std::move(config));
    if (XFAILED(s)) { REXLOG_ERROR("Setup failed: {:08X}", s); return false; }
    fprintf(stderr,"[BOOT] Setup OK\n"); fflush(stderr);
    if (!lh::InitNativeHeap()) { REXLOG_ERROR("Heap failed"); return false; }
    fprintf(stderr,"[BOOT] Heap OK\n"); fflush(stderr);
    s = runtime_->LoadXexImage("game:\\default.xex");
    if (XFAILED(s)) { REXLOG_ERROR("XEX failed: {:08X}", s); return false; }
    fprintf(stderr,"[BOOT] XEX OK\n"); fflush(stderr);
    // Register our hooks in the function dispatcher
    lh::RegisterHooks();
    void* previous_foreground = GetForegroundWindow();
    window_ = rex::ui::Window::Create(app_context(), "Fable II", uint32_t(REXCVAR_GET(window_width)),
                                      uint32_t(REXCVAR_GET(window_height)));
    if (!window_) { REXLOG_ERROR("Window failed"); return false; }
    window_->AddListener(this); window_->AddInputListener(this, 0);
    if (rex::cvar::Query<bool>("fullscreen")) window_->SetFullscreen(true);
    window_->Open();
    fprintf(stderr,"[BOOT] Window OK\n"); fflush(stderr);
    // Give the input drivers the window: the SDL driver initialises its events and
    // gamepad subsystems on the UI thread from here; without it XamInputGetState /
    // GetCapabilities assert once the game polls the pad.
    if (runtime_->input_system()) {
      static_cast<rex::input::InputSystem*>(runtime_->input_system())->AttachWindow(window_.get());
    }
    AutoTest_Start(static_cast<rex::input::InputSystem*>(runtime_->input_system()),
                   static_cast<rex::ui::Win32Window*>(window_.get())->hwnd(), previous_foreground);
    // Verify file I/O works from this process
  { FILE* f = fopen("main_io_test.log", "w"); if(f){fprintf(f,"MAIN OK\n");fclose(f);} }
  auto* gs = static_cast<rex::graphics::GraphicsSystem*>(runtime_->graphics_system());
    if (gs && gs->presenter()) {
      auto* p = gs->presenter(); auto* prov = gs->provider();
      if (prov) {
        immediate_drawer_ = prov->CreateImmediateDrawer();
        if (immediate_drawer_) {
          immediate_drawer_->SetPresenter(p);
          imgui_drawer_ = std::make_unique<rex::ui::ImGuiDrawer>(window_.get(), 64);
          imgui_drawer_->SetPresenterAndImmediateDrawer(p, immediate_drawer_.get());
          // The game's own debug displays (compiled out of retail, re-implemented natively): drawn
          // whenever the game's Debug.SetDrawGameFPS / SetDrawBuildVersion / SetDrawSafeArea flags are on.
          game_debug_overlay_ = std::make_unique<f2::debug::DebugOverlay>(imgui_drawer_.get());
          // Overlays are created on demand from hotkeys (same binds as rex_app):
          // F3 = debug stats, ` = console, F4 = settings. Creating them up front
          // hides the game behind three dialogs.
          rex::ui::RegisterBind("bind_debug_overlay", "F3", "Toggle debug overlay", [this] {
            if (debug_overlay_) debug_overlay_.reset();
            else debug_overlay_ = std::make_unique<rex::ui::DebugOverlayDialog>(imgui_drawer_.get());
          });
          rex::ui::RegisterBind("bind_console", "Backtick", "Toggle console overlay", [this] {
            if (console_overlay_) console_overlay_.reset();
            else console_overlay_ = std::make_unique<rex::ui::ConsoleDialog>(imgui_drawer_.get(), log_sink_);
          });
          // F9 = record the next frame at the D3D level (src/d3d_capture.cpp, native renderer work).
          rex::ui::RegisterBind("bind_d3d_capture", "F9", "Capture one frame of D3D calls", [] { D3DCapture_Request(); });
          rex::ui::RegisterBind("bind_native_history", "F6",
                                "Save the native renderer's frames of the last few seconds",
                                [] { NativeFrontend_RequestHistory(); });
          rex::ui::RegisterBind("bind_native_invalidate", "F8",
                                "Native renderer diagnostics: re-read all textures and geometry from game memory",
                                [] { NativeFrontend_RequestInvalidate(); });
          rex::ui::RegisterBind("bind_native_burst", "F7",
                                "Record every native-renderer frame (snapshot + trace) for 8 seconds",
                                [] { NativeFrontend_RequestBurst(); });
          rex::ui::RegisterBind("bind_native_snapshot", "F10", "Save the native renderer's next frame as a PNG",
                                [] { NativeFrontend_RequestSnapshot(); });
          rex::ui::RegisterBind("bind_fullscreen", "F11", "Toggle fullscreen", [this] {
            window_->SetFullscreen(!window_->IsFullscreen());
          });
          // F2 = Lionhead's shipped debug menu + Lua prompt (src/debug_menu.cpp, src/lua_bridge.cpp).
          rex::ui::RegisterBind("bind_debug_menu", "F2", "Toggle the game's debug menu / Lua prompt", [this, game_dir] {
            if (debug_menu_) debug_menu_->set_visible(!debug_menu_->visible());
            else debug_menu_ = std::make_unique<DebugMenuDialog>(imgui_drawer_.get(), game_dir / "data" / "scripts" / "Startup");
          });
          rex::ui::RegisterBind("bind_settings", "F4", "Toggle settings overlay", [this, config_path] {
            if (settings_overlay_) settings_overlay_.reset();
            else settings_overlay_ = std::make_unique<rex::ui::SettingsDialog>(imgui_drawer_.get(), config_path);
          });
          // Let the game keep the mouse unless an overlay is open and wants it.
          if (auto* input_sys = static_cast<rex::input::InputSystem*>(runtime_->input_system())) {
            input_sys->SetActiveCallback([this]() {
              // The debug menu owns mouse and keyboard while it is shown (frees the cursor
              // the MnK driver otherwise hides and re-centres every frame).
              if (debug_menu_ && debug_menu_->visible()) return false;
              if (AutoTest_Active()) return false;  // unattended run: leave the desktop mouse/keyboard alone
              if (!debug_overlay_ && !console_overlay_ && !settings_overlay_) return true;
              return !imgui_drawer_->GetIO().WantCaptureMouse;
            });
          }
          runtime_->set_display_window(window_.get()); runtime_->set_imgui_drawer(imgui_drawer_.get());
        }
      }
      window_->SetPresenter(p);
    }
    fprintf(stderr,"[BOOT] Launching\n"); fflush(stderr);
    app_context().CallInUIThreadDeferred([this](){
      fprintf(stderr,"[LAMBDA] CallInUIThreadDeferred fired\n"); fflush(stderr);
      // Same sequence as ReXApp::LaunchModule: create the main guest thread
      // suspended, attach the persistent shader/pipeline storage for this
      // title (blocking load of previously stored pipelines), then resume.
      auto t = runtime_->PrepareModuleLaunch();
      fprintf(stderr,"[LAMBDA] PrepareModuleLaunch returned: %p\n", (void*)t.get()); fflush(stderr);
      if(!t){app_context().QuitFromUIThread();return;}
      if (auto* gsys = static_cast<rex::graphics::GraphicsSystem*>(runtime_->graphics_system());
          gsys && !runtime_->cache_root().empty()) {
        uint32_t title_id = runtime_->kernel_state()->title_id();
        if (title_id != 0) {
          REXLOG_INFO("Initializing shader storage for title {:08X} in {}", title_id, runtime_->cache_root().string());
          gsys->InitializeShaderStorage(runtime_->cache_root(), title_id, true);
        }
      }
      if (rex::cvar::Query<bool>("native_renderer")) NativeGpuSync_Start();
      // Native mods (mods/<Mod>/native/*.dll next to the exe) replace game functions before any
      // game code runs.
      ModLoader_Initialize(rex::filesystem::GetExecutableFolder(), runtime_->memory()->virtual_membase());
      t->Resume();
      module_thread_=std::thread([this,t=std::move(t)]()mutable{
          fprintf(stderr,"[WAIT-THREAD] Waiting for guest to exit\n"); fflush(stderr);
          t->Wait(0,0,0,nullptr);
          NativeGpuSync_Stop();
          fprintf(stderr,"[WAIT-THREAD] Guest exited\n"); fflush(stderr);
          REXLOG_INFO("Guest exited");
      });
    });
    return true;
  }
  void OnKeyDown(rex::ui::KeyEvent& e) override{
    // Alt+Enter toggles fullscreen like most PC games.
    if (e.virtual_key() == rex::ui::VirtualKey::kReturn && e.is_alt_pressed() && window_) {
      if (!e.prev_state()) window_->SetFullscreen(!window_->IsFullscreen());
      e.set_handled(true);
      return;
    }
    rex::ui::ProcessKeyEvent(e);
  }
  void OnClosing(rex::ui::UIEvent& e) override{(void)e;shutting_down_.store(true);NativeGpuSync_Stop();if(runtime_&&runtime_->kernel_state())runtime_->kernel_state()->TerminateTitle();app_context().QuitFromUIThread();}
  void OnDestroy() override{
    rex::ui::UnregisterBind("bind_debug_overlay"); rex::ui::UnregisterBind("bind_console"); rex::ui::UnregisterBind("bind_settings"); rex::ui::UnregisterBind("bind_fullscreen"); rex::ui::UnregisterBind("bind_d3d_capture"); rex::ui::UnregisterBind("bind_native_snapshot"); rex::ui::UnregisterBind("bind_native_burst"); rex::ui::UnregisterBind("bind_native_history"); rex::ui::UnregisterBind("bind_native_invalidate"); rex::ui::UnregisterBind("bind_debug_menu");
    game_debug_overlay_.reset();debug_menu_.reset();settings_overlay_.reset();console_overlay_.reset();debug_overlay_.reset();
    if(imgui_drawer_){imgui_drawer_->SetPresenterAndImmediateDrawer(nullptr,nullptr);imgui_drawer_.reset();}
    if(immediate_drawer_){immediate_drawer_->SetPresenter(nullptr);immediate_drawer_.reset();}
    if(runtime_){runtime_->set_display_window(nullptr);runtime_->set_imgui_drawer(nullptr);}
    if(window_){window_->SetPresenter(nullptr);}
    if(module_thread_.joinable())module_thread_.join();
    if(window_){window_->RemoveInputListener(this);window_->RemoveListener(this);}
    window_.reset();runtime_.reset();
  }
 private:
  std::unique_ptr<rex::Runtime> runtime_; std::unique_ptr<rex::ui::Window> window_; std::thread module_thread_;
  std::atomic<bool> shutting_down_{false};
  std::unique_ptr<rex::ui::ImmediateDrawer> immediate_drawer_; std::unique_ptr<rex::ui::ImGuiDrawer> imgui_drawer_;
  std::shared_ptr<rex::LogCaptureSink> log_sink_;
  std::unique_ptr<rex::ui::DebugOverlayDialog> debug_overlay_; std::unique_ptr<rex::ui::ConsoleDialog> console_overlay_; std::unique_ptr<rex::ui::SettingsDialog> settings_overlay_;
  std::unique_ptr<DebugMenuDialog> debug_menu_;
  std::unique_ptr<f2::debug::DebugOverlay> game_debug_overlay_;
};
REX_DEFINE_APP(Fable2, Fable2App::Create)
