#ifndef WT_CLIENT_H
#define	WT_CLIENT_H

#include <stdint.h>
#include <SDL_rect.h>
#include <SDL_pixels.h>

namespace wt {
    namespace DEFAULT {
        extern const char*      GAME_WINDOW_TITLE;
        extern const SDL_Rect   GAME_WINDOW_POSITION;
        extern const SDL_Color  GAME_RENDER_DRAW_COLOR;
        extern const bool       GAME_WINDOW_FULLSCREEN_ENABLE;
        extern const uint32_t   GAME_FPS;
        extern const uint32_t   GAME_LOOP_TIMEOUT;
    }
}

#endif	/* WT_CLIENT_H */

