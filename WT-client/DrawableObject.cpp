#include "DrawableObject.h"
#include <SDL_image.h>
#include <iostream>

DrawableObject::DrawableObject(SDL_Renderer* const renderer)
    : renderer(renderer) 
{
}

void DrawableObject::load(const std::string& fileName) {
    SDL_Surface* tmp = IMG_Load(fileName.c_str());
    if (tmp == nullptr) {
        std::cerr << IMG_GetError() << '\n';
        std::clog << "Can't load image \"" << fileName << "\". Attempt to load default image ... ";
        tmp = IMG_Load("Resources/no_image.jpeg");
        if (tmp == nullptr) {
            std::cerr << IMG_GetError() << '\n';
            std::clog << "fail\n";
        } else {
            std::clog << "success\n";
        }
    }
    this->texture = SDL_CreateTextureFromSurface(this->renderer, tmp);
    SDL_FreeSurface(tmp);
    if (this->texture == nullptr) {
        std::cerr << "Can't create texture from surface\n";
    }
}

void DrawableObject::draw() const {
    SDL_Rect srcRect, dstRect;
    srcRect.x = srcRect.y = 0;
    SDL_QueryTexture(this->texture, nullptr, nullptr, &srcRect.w, &srcRect.h);
    dstRect.x = this->pos.x;
    dstRect.y = this->pos.y;
    dstRect.w = srcRect.w;
    dstRect.h = srcRect.h;
    SDL_RenderCopyEx(this->renderer, this->texture, &srcRect, &dstRect, 0, 0, SDL_FLIP_NONE);
}