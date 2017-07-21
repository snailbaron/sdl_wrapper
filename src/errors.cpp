#include "errors.hpp"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_net.h>
#include <SDL_ttf.h>

#include <map>
#include <cassert>

SdlError::SdlError(const char* (*getErrorFunc)())
    : _message(getErrorFunc())
{ }

const char* SdlError::what() const
{
    return _message.c_str();
}

[[noreturn]] void throwSdl() { throw SdlError(SDL_GetError); }
[[noreturn]] void throwImage() { throw SdlError(IMG_GetError); }
[[noreturn]] void throwMixer() { throw SdlError(Mix_GetError); }
[[noreturn]] void throwNet() { throw SdlError(SDLNet_GetError); }
[[noreturn]] void throwTtf() { throw SdlError(TTF_GetError); }
