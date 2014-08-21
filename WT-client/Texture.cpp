#include "Texture.h"
#include "Renderer.h"
#include "Surface.h"

Texture::Texture(SDL_Texture* texture) {
    this->texture = texture;
}

Texture::Texture(const Renderer* renderer, const Surface* surface) {
    this->texture = SDL_CreateTextureFromSurface(renderer->renderer, surface->surface);
    if (this->texture == nullptr) {
        SDL_Log(SDL_GetError());
    }
}

Texture::~Texture() {
    SDL_DestroyTexture(this->texture);
}

uint8_t Texture::getAlphaMod() const {
    uint8_t alpha;
    if (SDL_GetTextureAlphaMod(this->texture, &alpha)) {
        SDL_Log(SDL_GetError());
    }
    return alpha;
}

SDL_BlendMode Texture::getBlendMode() const {
    SDL_BlendMode blendMode;
    if (SDL_GetTextureBlendMode(this->texture, &blendMode)) {
        SDL_Log(SDL_GetError());
    }
    return blendMode;
}

SDL_Color Texture::getColorMod() const {
    SDL_Color colorMode;
    if (SDL_GetTextureColorMod(this->texture,
            &colorMode.r,
            &colorMode.g,
            &colorMode.b)) {
        SDL_Log(SDL_GetError());
    }
    return colorMode;
}

Size Texture::getSize() const {
    Size size;
    if (SDL_QueryTexture(this->texture, 0, 0, &size.rw(), &size.rh())) {
        SDL_Log(SDL_GetError());
    }
    return size;
}

void Texture::setBlendMode(const SDL_BlendMode& blendMode) {
    if (SDL_SetTextureBlendMode(this->texture, blendMode)) {
        SDL_Log(SDL_GetError());
    }
}

void Texture::setColorMod(const SDL_Color& color) {
    if (SDL_SetTextureColorMod(this->texture,
            color.r,
            color.g,
            color.b)) {
        SDL_Log(SDL_GetError());
    }
}