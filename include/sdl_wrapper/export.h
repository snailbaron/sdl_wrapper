#pragma once

#ifdef _WIN32
#   ifdef SDL_WRAPPER_BUILD
#       define __declspec(dllexport)
#   else
#       define __declspec(dllimport)
#   endif
#else
#   define EXPORT
#endif