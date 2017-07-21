#pragma once

#include <SDL.h>

namespace sdl {

/*
 * Configuration Variables
 */

namespace hint {

extern const auto AccelerometerAsJoystick;
extern const auto AndroidApkExpansionMainFileVersion;
extern const auto AndroidApkExpansionPatchFileVersion;
extern const auto AndroidSeparateMouseAndTouch;
extern const auto AppleTvControllerUiEvents;
extern const auto AppleTvRemoteAllowRotation;
extern const auto BmpSaveLegacyFormat;
extern const auto EmscriptenKeyboardElement;
extern const auto FramebufferAcceleration;
extern const auto Gamecontrollerconfig;
extern const auto GrabKeyboard;
extern const auto IdleTimerDisabled;
extern const auto ImeInternalEditing;
extern const auto JoystickAllowBackgroundEvents;
extern const auto MacBackgroundApp;
extern const auto MacCtrlClickEmulateRightClick;
extern const auto MouseFocusClickthrough;
extern const auto MouseRelativeModeWarp;
extern const auto NoSignalHandlers;
extern const auto Orientations;
extern const auto RenderDirect3d11Debug;
extern const auto RenderDirect3dThreadsafe;
extern const auto RenderDriver;
extern const auto RenderOpenglShaders;
extern const auto RenderScaleQuality;
extern const auto RenderVsync;
extern const auto RpiVideoLayer;
extern const auto ThreadStackSize;
extern const auto TimerResolution;
extern const auto VideoAllowScreensaver;
extern const auto VideoHighdpiDisabled;
extern const auto VideoMacFullscreenSpaces;
extern const auto VideoMinimizeOnFocusLoss;
extern const auto VideoWindowSharePixelFormat;
extern const auto VideoWinD3dcompiler;
extern const auto VideoX11NetWmPing;
extern const auto VideoX11Xinerama;
extern const auto VideoX11Xrandr;
extern const auto VideoX11Xvidmode;
extern const auto WindowsDisableThreadNaming;
extern const auto WindowsEnableMessageloop;
extern const auto WindowsNoCloseOnAltF4;
extern const auto WindowFrameUsableWhileCursorHidden;
extern const auto WinrtHandleBackButton;
extern const auto WinrtPrivacyPolicyLabel;
extern const auto WinrtPrivacyPolicyUrl;
extern const auto XinputEnabled;
extern const auto XinputUseOldJoystickMapping;

enum Priority {
    Default,
    Normal,
    Override,
};

} // namespace hint

// TODO: use enumeration instead of char* hint name?

typedef void (*HintCallback)(
    void* userdata,
    const char* name,
    const char* oldValue,
    const char* newValue);

void addHintCallback(const char* name, HintCallback callback, void* userdata);

void clearHints();

void delHintCallback(const char* name, HintCallback callback, void* userdata);

const char* getHint(const char* name);

bool getHintBoolean(const char* name, bool defaultValue);

bool setHint(const char* name, const char* value);

bool setHintWithPriority(
    const char* name, const char* value, hint::Priority priority);

} // namespace sdl