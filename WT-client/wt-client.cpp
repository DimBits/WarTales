#include "wt-client.h"
#include <SDL_video.h>

namespace wt {
    namespace DEFAULT {
        const char* WINDOW_TITLE = "War Tales";
        const SDL_Rect WINDOW_POSITION = {0, 0, 640, 480};
        const SDL_Color RENDER_DRAW_COLOR = {0x00, 0x00, 0x00, 0xFF};
        const uint32_t FPS = 60;
        const uint32_t LOOP_TIMEOUT = 1000.0f / FPS;
        const uint32_t WINDOW_FLAGS = SDL_WINDOW_RESIZABLE;

        const SDL_RendererFlip RENDERER_FLIP = SDL_FLIP_NONE;
    }
}