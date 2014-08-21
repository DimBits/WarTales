#include "Surface.h"
#include <SDL_image.h>

Surface::Surface(SDL_Surface* surface) {
    this->surface = surface;
}

Surface::Surface(const Size& size) {
    this->surface = SDL_CreateRGBSurface(0,
            size.width(),
            size.height(),
            DEFAULT::SURFACE_DEPTH,
            0, 0, 0, 0);
    if (this->surface == nullptr) {
        SDL_Log(SDL_GetError());
    }
}

Surface::Surface(const char* filePath) {
    this->surface = IMG_Load(filePath);
    if (this->surface == nullptr) {
        SDL_Log(SDL_GetError());
    }
}

Surface::~Surface() {
    SDL_FreeSurface(this->surface);
}

void Surface::blitScaled(const Surface* dst, const SDL_Rect* srcRect, SDL_Rect* dstRect) {
    if (SDL_BlitScaled(this->surface,
            srcRect,
            dst->surface,
            dstRect)) {
        SDL_Log(SDL_GetError());
    }
}

void Surface::blit(const Surface* dst, const SDL_Rect* srcRect, SDL_Rect* dstRect) {
    if (SDL_BlitSurface(this->surface,
            srcRect,
            dst->surface,
            dstRect)) {
        SDL_Log(SDL_GetError());
    }
}

void Surface::fillRect(const SDL_Rect* rect, const SDL_Color& color) {
    if (SDL_FillRect(this->surface,
            rect,
            SDL_MapRGB(this->surface->format, color.r, color.g, color.b))) {
        SDL_Log(SDL_GetError());
    }
}

void Surface::fillRects(const std::vector<SDL_Rect>& rects, const SDL_Color& color) {
    if (SDL_FillRects(this->surface,
            rects.data(),
            rects.size(),
            SDL_MapRGB(this->surface->format, color.r, color.g, color.b))) {
        SDL_Log(SDL_GetError());
    }
}

SDL_Rect Surface::getClipRect() const {
    SDL_Rect clipRect;
    SDL_GetClipRect(this->surface, &clipRect);
    return clipRect;
}

SDL_Color Surface::getColorKey() const {
    uint32_t key;
    if (SDL_GetColorKey(this->surface, &key)) {
        SDL_Log(SDL_GetError());
    }
    SDL_Color color;
    SDL_GetRGB(key, this->surface->format, &color.r, &color.g, &color.b);
    return color;
}

uint8_t Surface::getAlphaMod() const {
    uint8_t alphaMod;
    if (SDL_GetSurfaceAlphaMod(this->surface, &alphaMod)) {
        SDL_Log(SDL_GetError());
    }
    return alphaMod;
}

SDL_BlendMode Surface::getBlendMode() const {
    SDL_BlendMode blendMode;
    if (SDL_GetSurfaceBlendMode(this->surface, &blendMode)) {
        SDL_Log(SDL_GetError());
    }
    return blendMode;
}

SDL_Color Surface::getColorMod() const {
    SDL_Color colorMod;
    if (SDL_GetSurfaceColorMod(this->surface,
            &colorMod.r,
            &colorMod.g,
            &colorMod.b)) {
        SDL_Log(SDL_GetError());
    }
    return colorMod;
}

void Surface::setColorKey(const SDL_Color& color, bool state) {
    SDL_bool sdlState = SDL_FALSE;
    if (state) {
        sdlState = SDL_TRUE;
    }
    if (SDL_SetColorKey(this->surface,
            sdlState,
            SDL_MapRGB(this->surface->format, color.r, color.g, color.b))) {
        SDL_Log(SDL_GetError());
    }
}

bool Surface::setClipRect(const SDL_Rect* rect) {
    SDL_bool sdlBool = SDL_SetClipRect(this->surface, rect);
    bool state = false;
    if (sdlBool == SDL_TRUE) {
        state = true;
    }
    return state;
}

void Surface::setAlphaMod(uint8_t alpha) {
    if (SDL_SetSurfaceAlphaMod(this->surface, alpha)) {
        SDL_Log(SDL_GetError());
    }
}

void Surface::setBlendMode(const SDL_BlendMode& blendMode) {
    if (SDL_SetSurfaceBlendMode(this->surface, blendMode)) {
        SDL_Log(SDL_GetError());
    }
}

void Surface::setColorMod(const SDL_Color& color) {
    if (SDL_SetSurfaceColorMod(this->surface,
            color.r,
            color.g,
            color.b)) {
        SDL_Log(SDL_GetError());
    }
}