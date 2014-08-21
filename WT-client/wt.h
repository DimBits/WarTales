#ifndef WT_H
#define	WT_H

#include <utility>
#include <SDL.h>

class Size : std::pair<int32_t, int32_t> {
public:
    Size() = default;
    Size(int32_t width, int32_t height);
    int32_t width() const;
    int32_t height() const;
    void width(int32_t width);
    void height(int32_t height);
    int32_t& rw();
    int32_t& rh();
};

class Scale : std::pair<float, float> {
public:
    Scale() = default;
    Scale(float x, float y);
    float x() const;
    float y() const;
    float& rx();
    float& ry();
};

namespace DEFAULT {
    extern const char* WINDOW_TITLE;
    extern const SDL_Rect WINDOW_POSITION;
    extern const SDL_Color RENDER_DRAW_COLOR;
    extern const uint32_t FPS;
    extern const uint32_t LOOP_TIMEOUT;
    extern const uint32_t WINDOW_FLAGS;

    extern const SDL_RendererFlip RENDERER_FLIP;
    extern const SDL_RendererFlags RENDERER_FLAGS;
    
    extern const int32_t SURFACE_DEPTH;
}

#endif	/* WT_H */

