#include "sdl_hints.hpp"

#include <SDL_hints.h>

#include <cassert>

namespace sdl {

namespace {

SDL_HintPriority toSdl(hint::Priority priority)
{
    switch (priority) {
        case hint::Priority::Default: return SDL_HINT_DEFAULT;
        case hint::Priority::Normal: return SDL_HINT_NORMAL;
        case hint::Priority::Override: return SDL_HINT_OVERRIDE;
    }
    assert(false);
    return (SDL_HintPriority)0;
}

} // namespace

namespace hint {

const auto AccelerometerAsJoystick             = SDL_HINT_ACCELEROMETER_AS_JOYSTICK;
const auto AndroidApkExpansionMainFileVersion  = SDL_HINT_ANDROID_APK_EXPANSION_MAIN_FILE_VERSION;
const auto AndroidApkExpansionPatchFileVersion = SDL_HINT_ANDROID_APK_EXPANSION_PATCH_FILE_VERSION;
const auto AndroidSeparateMouseAndTouch        = SDL_HINT_ANDROID_SEPARATE_MOUSE_AND_TOUCH;
const auto AppleTvControllerUiEvents           = SDL_HINT_APPLE_TV_CONTROLLER_UI_EVENTS;
const auto AppleTvRemoteAllowRotation          = SDL_HINT_APPLE_TV_REMOTE_ALLOW_ROTATION;
const auto BmpSaveLegacyFormat                 = SDL_HINT_BMP_SAVE_LEGACY_FORMAT;
const auto EmscriptenKeyboardElement           = SDL_HINT_EMSCRIPTEN_KEYBOARD_ELEMENT;
const auto FramebufferAcceleration             = SDL_HINT_FRAMEBUFFER_ACCELERATION;
const auto Gamecontrollerconfig                = SDL_HINT_GAMECONTROLLERCONFIG;
const auto GrabKeyboard                        = SDL_HINT_GRAB_KEYBOARD;
const auto IdleTimerDisabled                   = SDL_HINT_IDLE_TIMER_DISABLED;
const auto ImeInternalEditing                  = SDL_HINT_IME_INTERNAL_EDITING;
const auto JoystickAllowBackgroundEvents       = SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS;
const auto MacBackgroundApp                    = SDL_HINT_MAC_BACKGROUND_APP;
const auto MacCtrlClickEmulateRightClick       = SDL_HINT_MAC_CTRL_CLICK_EMULATE_RIGHT_CLICK;
const auto MouseFocusClickthrough              = SDL_HINT_MOUSE_FOCUS_CLICKTHROUGH;
const auto MouseRelativeModeWarp               = SDL_HINT_MOUSE_RELATIVE_MODE_WARP;
const auto NoSignalHandlers                    = SDL_HINT_NO_SIGNAL_HANDLERS;
const auto Orientations                        = SDL_HINT_ORIENTATIONS;
const auto RenderDirect3d11Debug               = SDL_HINT_RENDER_DIRECT3D11_DEBUG;
const auto RenderDirect3dThreadsafe            = SDL_HINT_RENDER_DIRECT3D_THREADSAFE;
const auto RenderDriver                        = SDL_HINT_RENDER_DRIVER;
const auto RenderOpenglShaders                 = SDL_HINT_RENDER_OPENGL_SHADERS;
const auto RenderScaleQuality                  = SDL_HINT_RENDER_SCALE_QUALITY;
const auto RenderVsync                         = SDL_HINT_RENDER_VSYNC;
const auto RpiVideoLayer                       = SDL_HINT_RPI_VIDEO_LAYER;
const auto ThreadStackSize                     = SDL_HINT_THREAD_STACK_SIZE;
const auto TimerResolution                     = SDL_HINT_TIMER_RESOLUTION;
const auto VideoAllowScreensaver               = SDL_HINT_VIDEO_ALLOW_SCREENSAVER;
const auto VideoHighdpiDisabled                = SDL_HINT_VIDEO_HIGHDPI_DISABLED;
const auto VideoMacFullscreenSpaces            = SDL_HINT_VIDEO_MAC_FULLSCREEN_SPACES;
const auto VideoMinimizeOnFocusLoss            = SDL_HINT_VIDEO_MINIMIZE_ON_FOCUS_LOSS;
const auto VideoWindowSharePixelFormat         = SDL_HINT_VIDEO_WINDOW_SHARE_PIXEL_FORMAT;
const auto VideoWinD3dcompiler                 = SDL_HINT_VIDEO_WIN_D3DCOMPILER;
const auto VideoX11NetWmPing                   = SDL_HINT_VIDEO_X11_NET_WM_PING;
const auto VideoX11Xinerama                    = SDL_HINT_VIDEO_X11_XINERAMA;
const auto VideoX11Xrandr                      = SDL_HINT_VIDEO_X11_XRANDR;
const auto VideoX11Xvidmode                    = SDL_HINT_VIDEO_X11_XVIDMODE;
const auto WindowsDisableThreadNaming          = SDL_HINT_WINDOWS_DISABLE_THREAD_NAMING;
const auto WindowsEnableMessageloop            = SDL_HINT_WINDOWS_ENABLE_MESSAGELOOP;
const auto WindowsNoCloseOnAltF4               = SDL_HINT_WINDOWS_NO_CLOSE_ON_ALT_F4;
const auto WindowFrameUsableWhileCursorHidden  = SDL_HINT_WINDOW_FRAME_USABLE_WHILE_CURSOR_HIDDEN;
const auto WinrtHandleBackButton               = SDL_HINT_WINRT_HANDLE_BACK_BUTTON;
const auto WinrtPrivacyPolicyLabel             = SDL_HINT_WINRT_PRIVACY_POLICY_LABEL;
const auto WinrtPrivacyPolicyUrl               = SDL_HINT_WINRT_PRIVACY_POLICY_URL;
const auto XinputEnabled                       = SDL_HINT_XINPUT_ENABLED;
const auto XinputUseOldJoystickMapping         = SDL_HINT_XINPUT_USE_OLD_JOYSTICK_MAPPING;

} // namespace hint

void addHintCallback(const char* name, HintCallback callback, void* userdata)
{
    SDL_AddHintCallback(name, callback, userdata);
}

void clearHints()
{
    SDL_ClearHints();
}

void delHintCallback(const char* name, HintCallback callback, void* userdata)
{
    SDL_DelHintCallback(name, callback, userdata);
}

const char* getHint(const char* name)
{
    return SDL_GetHint(name);
}

bool getHintBoolean(const char* name, bool defaultValue)
{
    return SDL_GetHintBoolean(name, defaultValue ? SDL_TRUE : SDL_FALSE);
}

bool setHint(const char* name, const char* value)
{
    return SDL_SetHint(name, value);
}

bool setHintWithPriority(
    const char* name, const char* value, hint::Priority priority)
{
    return SDL_SetHintWithPriority(name, value, toSdl(priority));
}


} // namespace sdl