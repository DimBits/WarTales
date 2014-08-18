#ifndef WT_CLIENT_H
#define	WT_CLIENT_H

#include <stdint.h>
#include <SDL_rect.h>
#include <SDL_pixels.h>
#include <SDL_render.h>

namespace wt {
    namespace DEFAULT {
        extern const char* WINDOW_TITLE;
        extern const SDL_Rect WINDOW_POSITION;
        extern const SDL_Color RENDER_DRAW_COLOR;
        extern const uint32_t FPS;
        extern const uint32_t LOOP_TIMEOUT;
        extern const uint32_t WINDOW_FLAGS;
        
        extern const SDL_RendererFlip RENDERER_FLIP;
    }
}

#endif	/* WT_CLIENT_H */

