#pragma once

#include <cstdint>

namespace sdl {

/*
 * Initialization and Shutdown
 */

using InitFlags = uint32_t;

extern const InitFlags InitTimer;
extern const InitFlags InitAudio;
extern const InitFlags InitVideo;
extern const InitFlags InitJoystick;
extern const InitFlags InitHaptic;
extern const InitFlags InitGamecontroller;
extern const InitFlags InitEvents;
extern const InitFlags InitEverything;
extern const InitFlags InitNoparachute;

void init(InitFlags flags);

void initSubSystem(InitFlags flags);

void quit();

void quitSubSystem(InitFlags flags);

void setMainReady();

InitFlags wasInit(InitFlags flags);

} // namespace sdl