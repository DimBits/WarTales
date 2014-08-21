#include "Renderer.h"
#include "Texture.h"
#include "Window.h"

Renderer::Renderer(const Window* window) {
    this->renderer = SDL_CreateRenderer(window->window, -1, SDL_RENDERER_ACCELERATED);
    if (this->renderer == nullptr) {
        SDL_Log(SDL_GetError());
    }
}

Renderer::Renderer(SDL_Renderer* renderer) {
    this->renderer = renderer;
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(this->renderer);
}

SDL_BlendMode Renderer::getDrawBlendMode() const {
    SDL_BlendMode blendMode;
    if (SDL_GetRenderDrawBlendMode(this->renderer, &blendMode)) {
        SDL_Log(SDL_GetError());
    }
    return blendMode;
}

SDL_Color Renderer::getDrawColor() const {
    SDL_Color drawColor;
    if (SDL_GetRenderDrawColor(this->renderer,
            &drawColor.r,
            &drawColor.g,
            &drawColor.b,
            &drawColor.a)) {
        SDL_Log(SDL_GetError());
    }
    return drawColor;
}

Texture* Renderer::getTarget() const {
    return new Texture(SDL_GetRenderTarget(this->renderer));
}

Size Renderer::getOutputSize() const {
    Size outputSize;
    if (SDL_GetRendererOutputSize(this->renderer, &outputSize.rw(), &outputSize.rh())) {
        SDL_Log(SDL_GetError());
    }
    return outputSize;
}

void Renderer::clear() {
    if (SDL_RenderClear(this->renderer)) {
        SDL_Log(SDL_GetError());
    }
}

void Renderer::drawTexture(const Texture* texture, const SDL_Rect* srcRect, const SDL_Rect* dstRect) {
    if (SDL_RenderCopy(this->renderer, texture->texture, srcRect, dstRect)) {
        SDL_Log(SDL_GetError());
    }
}

void Renderer::drawTexture(const Texture* texture, const SDL_Rect* srcRect, const SDL_Rect* dstRect, double degrees, const SDL_Point* center, const SDL_RendererFlip flip) {
    if (SDL_RenderCopyEx(this->renderer,
            texture->texture,
            srcRect,
            dstRect,
            degrees,
            center,
            flip)) {
        SDL_Log(SDL_GetError());
    }
}

void Renderer::drawLine(const SDL_Point& x1, const SDL_Point& x2) {
    if (SDL_RenderDrawLine(this->renderer,
            x1.x,
            x1.y,
            x2.x,
            x2.y)) {
        SDL_Log(SDL_GetError());
    }
}

void Renderer::drawLines(const std::vector<SDL_Point>& points) {
    if (SDL_RenderDrawLines(this->renderer, points.data(), points.size())) {
        SDL_Log(SDL_GetError());
    }
}

void Renderer::drawPoint(const SDL_Point& point) {
    if (SDL_RenderDrawPoint(this->renderer, point.x, point.y)) {
        SDL_Log(SDL_GetError());
    }
}

void Renderer::drawPoints(const std::vector<SDL_Point>& points) {
    if (SDL_RenderDrawPoints(this->renderer, points.data(), points.size())) {
        SDL_Log(SDL_GetError());
    }
}

void Renderer::drawRect(const SDL_Rect* rect) {
    if (SDL_RenderDrawRect(this->renderer, rect)) {
        SDL_Log(SDL_GetError());
    }
}

void Renderer::drawRects(const std::vector<SDL_Rect>& rects) {
    if (SDL_RenderDrawRects(this->renderer, rects.data(), rects.size())) {
        SDL_Log(SDL_GetError());
    }
}

void Renderer::fillRect(const SDL_Rect* rect) {
    if (SDL_RenderFillRect(this->renderer, rect)) {
        SDL_Log(SDL_GetError());
    }
}

void Renderer::fillRects(const std::vector<SDL_Rect>& rects) {
    if (SDL_RenderFillRects(this->renderer, rects.data(), rects.size())) {
        SDL_Log(SDL_GetError());
    }
}

SDL_Rect Renderer::getClipRect() const {
    SDL_Rect clipRect;
    SDL_RenderGetClipRect(this->renderer, &clipRect);
    return clipRect;
}

Size Renderer::getLogicalSize() const {
    Size logicalSize;
    SDL_RenderGetLogicalSize(this->renderer, &logicalSize.rw(), &logicalSize.rh());
    return logicalSize;
}

Scale Renderer::getScale() const {
    Scale scale;
    SDL_RenderGetScale(this->renderer, &scale.rx(), &scale.ry());
    return scale;
}

SDL_Rect Renderer::getViewport() const {
    SDL_Rect viewport;
    SDL_RenderGetViewport(this->renderer, &viewport);
    return viewport;
}

void Renderer::present() {
    SDL_RenderPresent(this->renderer);
}

void Renderer::setClipRect(const SDL_Rect* rect) {
    if (SDL_RenderSetClipRect(this->renderer, rect)) {
        SDL_Log(SDL_GetError());
    }
}

void Renderer::setLogicalSize(const Size& size) {
    if (SDL_RenderSetLogicalSize(this->renderer, size.width(), size.height())) {
        SDL_Log(SDL_GetError());
    }
}

void Renderer::setScale(const Scale& scale) {
    if (SDL_RenderSetScale(this->renderer, scale.x(), scale.y())) {
        SDL_Log(SDL_GetError());
    }
}

void Renderer::setViewport(const SDL_Rect* rect) {
    if (SDL_RenderSetViewport(this->renderer, rect)) {
        SDL_Log(SDL_GetError());
    }
}

bool Renderer::isTargetSupported() const {
    bool state = false;
    SDL_bool sdlState = SDL_RenderTargetSupported(this->renderer);
    if (sdlState == SDL_TRUE) {
        state = true;
    }
    return state;
}

void Renderer::setDrawBlendMode(const SDL_BlendMode& blendMode) {
    if (SDL_SetRenderDrawBlendMode(this->renderer, blendMode)) {
        SDL_Log(SDL_GetError());
    }
}

void Renderer::setDrawColor(const SDL_Color& drawColor) {
    if (SDL_SetRenderDrawColor(this->renderer,
            drawColor.r,
            drawColor.g,
            drawColor.b,
            drawColor.a)) {
        SDL_Log(SDL_GetError());
    }
}

void Renderer::setTarget(const Texture* target) {
    if (SDL_SetRenderTarget(this->renderer, target->texture)) {
        SDL_Log(SDL_GetError());
    }
}