#include "wt-client.h"
#include <SDL_video.h>

namespace wt {
    namespace DEFAULT {
        const char* GAME_WINDOW_TITLE = "War Tales";
        const SDL_Rect GAME_WINDOW_POSITION = {0, 0, 640, 480};
        const SDL_Color GAME_RENDER_DRAW_COLOR = {0x00, 0x00, 0x00, 0xFF};
        const uint32_t GAME_FPS = 60;
        const uint32_t GAME_LOOP_TIMEOUT = 1000.0f / GAME_FPS;
        const uint32_t GAME_WINDOW_FLAGS = SDL_WINDOW_RESIZABLE;

        const SDL_RendererFlip RENDERER_FLIP = SDL_FLIP_NONE;
    }
}