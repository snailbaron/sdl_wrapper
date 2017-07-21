#include <sdl_wrapper/sdl.hpp>

#include "errors.hpp"

#include <SDL.h>

#include <cassert>

namespace sdl {

namespace {

extern const InitFlags InitTimer = SDL_INIT_TIMER;
extern const InitFlags InitAudio = SDL_INIT_AUDIO;
extern const InitFlags InitVideo = SDL_INIT_VIDEO;
extern const InitFlags InitJoystick = SDL_INIT_JOYSTICK;
extern const InitFlags InitHaptic = SDL_INIT_HAPTIC;
extern const InitFlags InitGamecontroller = SDL_INIT_GAMECONTROLLER;
extern const InitFlags InitEvents = SDL_INIT_EVENTS;
extern const InitFlags InitEverything = SDL_INIT_EVERYTHING;
extern const InitFlags InitNoparachute = SDL_INIT_NOPARACHUTE;

} // namespace

//
// Initialization and shutdown
//

void init(InitFlags flags)
{
    if (SDL_Init(flags) != 0) {
        throwSdl();
    }
}

void initSubSystem(InitFlags flags)
{
    if (SDL_InitSubSystem(flags) != 0) {
        throwSdl();
    }
}

void quit()
{
    SDL_Quit();
}

void quitSubSystem(InitFlags flags)
{
    SDL_QuitSubSystem(flags);
}

void setMainReady()
{
    SDL_SetMainReady();
}

InitFlags wasInit(InitFlags flags)
{
    return SDL_WasInit(flags);
}

// NOT IMPLEMENTED: SDL_WinRTRunApp

} // namespace sdl
