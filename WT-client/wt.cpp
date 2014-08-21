#include "wt.h"
#include <SDL_video.h>

Size::Size(int32_t width, int32_t height) {
    this->first = width;
    this->second = height;
}

int32_t Size::width() const {
    return this->first;
}

int32_t Size::height() const {
    return this->second;
}

void Size::width(int32_t width) {
    this->first = width;
}

void Size::height(int32_t height) {
    this->second = height;
}

int32_t& Size::rw() {
    return this->first;
}

int32_t& Size::rh() {
    return this->second;
}

Scale::Scale(float x, float y) {
    this->first = x;
    this->second = y;
}

float Scale::x() const {
    return this->first;
}

float Scale::y() const {
    return this->second;
}

float& Scale::rx() {
    return this->first;
}

float& Scale::ry() {
    return this->second;
}

namespace DEFAULT {
    const char* WINDOW_TITLE = "War Tales";
    const SDL_Rect WINDOW_POSITION = {0, 0, 640, 480};
    const SDL_Color RENDER_DRAW_COLOR = {0x00, 0x00, 0x00, 0xFF};
    const uint32_t FPS = 60;
    const uint32_t LOOP_TIMEOUT = 1000.0f / FPS;
    const uint32_t WINDOW_FLAGS = SDL_WINDOW_RESIZABLE;

    const SDL_RendererFlip RENDERER_FLIP = SDL_FLIP_NONE;
    const SDL_RendererFlags RENDERER_FLAGS = SDL_RENDERER_ACCELERATED;
    
    const int32_t SURFACE_DEPTH = 32;
}