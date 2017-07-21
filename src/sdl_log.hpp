#pragma once

#include <SDL_log.h>

namespace sdl {

namespace log {

enum class Category {
    Application,
    Error,
    Assert,
    System,
    Audio,
    Video,
    Render,
    Input,
    Test,
    Reserved1,
    Reserved2,
    Reserved3,
    Reserved4,
    Reserved5,
    Reserved6,
    Reserved7,
    Reserved8,
    Reserved9,
    Reserved10,
    Custom,
};

enum class Priority {
    Verbose,
    Debug,
    Info,
    Warn,
    Error,
    Critical,
};

} // namespace log

void log(const char* fmt, ...);

} // namespace sdl