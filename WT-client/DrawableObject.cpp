#include "DrawableObject.h"
#include <SDL_image.h>
#include <cmath>
#include <iostream>

DrawableObject::DrawableObject(SDL_Renderer* const renderer)
    : renderer(renderer) {
}

void DrawableObject::setRotationCenter(const SDL_Point& point) {
    this->rotationCenter = point;
}

void DrawableObject::setRotationCenter(uint16_t x, uint16_t y) {
    this->rotationCenter.x = x;
    this->rotationCenter.y = y;
}

const SDL_Point& DrawableObject::getRotationCenter() const {
    return this->rotationCenter;
}

void DrawableObject::setAngle(float angle) {
    this->rotationAngle = angle;
}

double DrawableObject::getAngle() const {
    return this->rotationAngle;
}

void DrawableObject::setX(uint16_t x) {
    this->dstRect.x = x;
}

void DrawableObject::setY(uint16_t y) {
    this->dstRect.y = y;
}

uint16_t DrawableObject::getX() const {
    return this->dstRect.x;
}

uint16_t DrawableObject::getY() const {
    return this->dstRect.y;
}

void DrawableObject::setSourceRectangle(const SDL_Rect& rectangle) {
    this->srcRect = rectangle;
}

void DrawableObject::setSourceRectangle(uint16_t x, uint16_t y, uint16_t w, uint16_t h) {
    this->srcRect.x = x;
    this->srcRect.y = y;
    this->srcRect.w = w;
    this->srcRect.h = h;
}

void DrawableObject::setDestinationRectangle(const SDL_Rect& rectangle) {
    this->dstRect = rectangle;
}

void DrawableObject::setDestinationRectangle(uint16_t x, uint16_t y, uint16_t w, uint16_t h) {
    this->dstRect.x = x;
    this->dstRect.y = y;
    this->dstRect.w = w;
    this->dstRect.h = h;
}

void DrawableObject::setPosition(const SDL_Point& position) {
    this->setX(position.x);
    this->setY(position.y);
}

void DrawableObject::setPosition(uint16_t x, uint16_t y) {
    this->setX(x);
    this->setY(y);
}

uint16_t DrawableObject::getWidth() const {
    return this->dstRect.w;
}

uint16_t DrawableObject::getHeight() const {
    return this->dstRect.h;
}

const SDL_Point DrawableObject::getPosition() const {
    return {this->getX(), this->getY()};
}

void DrawableObject::load(const char* imageFileName) {
    SDL_Surface* tmp = IMG_Load(imageFileName);
    if (tmp == nullptr) {
        std::clog << "Can't load image \"" << imageFileName << "\"\n";
        std::cerr << IMG_GetError() << '\n';
    }
    this->texture = SDL_CreateTextureFromSurface(this->renderer, tmp);
    SDL_FreeSurface(tmp);
    if (this->texture == nullptr) {
        std::clog << "Can't create texture from surface\n";
        std::cerr << SDL_GetError() << '\n';
    }
    this->srcRect.x = this->srcRect.y = 0;
    SDL_QueryTexture(this->texture, nullptr, nullptr, &this->srcRect.w, &this->srcRect.h);
    this->dstRect.w = this->srcRect.w;
    this->dstRect.h = this->srcRect.h;
    this->setRotationCenter(this->getWidth() / 2, this->getHeight() / 2);
}

void DrawableObject::draw() {
    if (!SDL_RenderCopyEx(this->renderer,
            this->texture,
            &this->srcRect,
            &this->dstRect,
            this->rotationAngle,
            &this->rotationCenter,
            this->rendererFlip)) {
        std::clog << "Can't draw texture\n";
        std::cerr << SDL_GetError() << '\n';
    }
}

void DrawableObject::setRendererFlip(const SDL_RendererFlip& rendererFlip) {
    this->rendererFlip = rendererFlip;
}