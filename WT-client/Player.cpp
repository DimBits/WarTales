#include "Player.h"
#include "Game.h"

Player::Player()
    : DrawableObject(Game::getInstance()->getRenderer()) {
    
}

void Player::onKeyDown(SDL_Event& event) {
    switch (event.key.keysym.sym) {
        case SDLK_LEFT:
            this->setX(this->getX() - 1);
            break;
        case SDLK_RIGHT:
            this->setX(this->getX() + 1);
            break;
        case SDLK_UP:
            this->setY(this->getY() - 1);
            break;
        case SDLK_DOWN:
            this->setY(this->getY() + 1);
            break;
    }
}

void Player::onKeyUp(SDL_Event& event) {
    
}

void Player::onMouseMove(SDL_Event& event) {
    this->setPosition(event.motion.x - this->getWidth() / 2, event.motion.y - this->getHeight() / 2);
}

void Player::onMouseButtonDown(SDL_Event& event) {
    int32_t width, height;
    Game::getInstance()->getSize(width, height);
    width += 50;
    height += 50;
    Game::getInstance()->setSize(width, height);
}

void Player::onMouseButtonUp(SDL_Event& event) {
    int32_t width, height;
    Game::getInstance()->getSize(width, height);
    width -= 50;
    height -= 50;
    Game::getInstance()->setSize(width, height);
}

void Player::onMouseWheel(SDL_Event& event) {
    this->setAngle(this->getAngle() + 30);
}