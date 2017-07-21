#pragma once

#include <sdl_wrapper/export.h>
#include <sdl_wrapper/sdl/render.hpp>
#include <sdl_wrapper/sdl/surface.hpp>
#include <sdl_wrapper/sdl/video.hpp>

#include <cstdint>
#include <string>

namespace sdl {

void init();
void initSubSystem(uint32_t flags);
void quit();
void quitSubSystem(uint32_t flags);
uint32_t wasInit(uint32_t flags);

std::shared_ptr<Window> createWindow(
    const std::string& title, int x, int y, int w, int h, uint32_t flags);

uint32_t getTicks();

} // namespace sdl