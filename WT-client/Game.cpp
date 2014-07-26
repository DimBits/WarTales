#include "Game.h"
#include <iostream>
#include <sstream>

Game::Game() {
    int32_t flags = 0;
    this->position = position;
    if (this->fullscreenEnable) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    std::clog << "Attempt to initialize SDL ... ";
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::clog << "success\n";
        std::clog << "Attempt to initialize window ... ";
        this->window = SDL_CreateWindow(this->title.c_str(),
                this->position.x,
                this->position.y,
                this->position.w,
                this->position.h,
                flags);
        if (this->window != nullptr) {
            std::clog << "success\n";
            std::clog << "Attempt to initialize renderer ... ";
            this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
            if (this->renderer != nullptr) {
                std::clog << "success\n";
                this->setRenderDrawColor(this->renderDrawColor);
            } else {
                std::clog << "fail\n";
                std::cerr << "Can't initialize renderer\n";
            }
        } else {
            std::clog << "fail\n";
            std::cerr << "Can't initialize window\n";
        }
    } else {
        std::clog << "fail\n";
        std::cerr << "Can't initialize SDL\n";
    }
    this->running = true;
    Game::instance = this;
}

Game::~Game() {
    std::clog << "Destroying renderer\n";
    SDL_DestroyRenderer(this->renderer);
    std::clog << "Destroying window\n";
    SDL_DestroyWindow(this->window);
    std::clog << "Closing SDL\n";
    SDL_Quit();
}

void Game::setTitle(const std::string& title) {
    this->title = title;
    SDL_SetWindowTitle(this->window, this->title.c_str());
}

const std::string& Game::getTitle() const {
    return this->title;
}

void Game::setRenderDrawColor(const SDL_Color& color) {
    this->renderDrawColor = color;
    SDL_SetRenderDrawColor(this->renderer,
            this->renderDrawColor.r,
            this->renderDrawColor.g,
            this->renderDrawColor.b,
            this->renderDrawColor.a);
}

void Game::exec() {
    Uint32 frameStart, frameTime;
    while (this->running) {
        frameStart = SDL_GetTicks();
        this->processEvents();
        this->render();
        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < wt::DEFAULT::GAME_LOOP_TIMEOUT) {
            SDL_Delay(static_cast<Uint32>(wt::DEFAULT::GAME_LOOP_TIMEOUT - frameTime));
        }
    }
}

void Game::processEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                this->onQuit();
                break;
        }
    }
}

void Game::onQuit() {
    this->quit();
}

void Game::render() {
    SDL_RenderClear(this->renderer);
    this->objectManager.render();
    SDL_RenderPresent(this->renderer);
}

Game* Game::getInstance() {
    return Game::instance;
}

SDL_Window* Game::getWindow() const {
    return this->window;
}

SDL_Renderer* Game::getRenderer() const {
    return this->renderer;
}

const SDL_Rect& Game::getPosition() const
{
    return this->position;
}

bool Game::isRunning() const {
    return this->running;
}

void Game::quit() {
    this->running = false;
}

Game* Game::instance;