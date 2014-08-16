#include "Game.h"
#include <iostream>

Game::Game() {
    std::clog << "Attempt to initialize SDL ... ";
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::clog << "success\n";
        std::clog << "Attempt to initialize window ... ";
        SDL_Rect position = wt::DEFAULT::GAME_WINDOW_POSITION;
        this->window = SDL_CreateWindow(wt::DEFAULT::GAME_WINDOW_TITLE,
                position.x,
                position.y,
                position.w,
                position.h,
                this->flags);
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
    Game::instance = this;
    this->objectManager = new ObjectManager;
}

Game::~Game() {
    delete this->objectManager;
    std::clog << "Destroying renderer\n";
    SDL_DestroyRenderer(this->renderer);
    std::clog << "Destroying window\n";
    SDL_DestroyWindow(this->window);
    std::clog << "Closing SDL\n";
    SDL_Quit();
}

void Game::setWindowFlags(const uint32_t flags) {
    this->flags = flags;
}

void Game::setTitle(const char* title) {
    SDL_SetWindowTitle(this->window, title);
}

const char* Game::getTitle() const {
    return SDL_GetWindowTitle(this->window);
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
    this->running = true;
    uint32_t frameStart, frameTime;
    while (this->running) {
        frameStart = SDL_GetTicks();
        this->processEvents();
        this->render();
        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < wt::DEFAULT::GAME_LOOP_TIMEOUT) {
            SDL_Delay(static_cast<uint32_t>(wt::DEFAULT::GAME_LOOP_TIMEOUT - frameTime));
        }
    }
}

void Game::processEvent(SDL_Event& event) {
    switch (event.type) {
        case SDL_QUIT:
            this->onQuit();
            break;
        default:
            this->objectManager->processEvent(event);
            break;
    }
}

void Game::processEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        this->processEvent(event);
    }
}

void Game::onQuit() {
    this->quit();
}

void Game::render() {
    SDL_RenderClear(this->renderer);
    this->objectManager->render();
    SDL_RenderPresent(this->renderer);
}

Game* Game::getInstance() {
    return Game::instance;
}

SDL_Window* Game::getWindow() const {
    return this->window;
}

void Game::getSize(int32_t& width, int32_t& height) const {
    SDL_GetWindowSize(this->window, &width, &height);
}

void Game::setSize(int32_t width, int32_t height) {
    SDL_SetWindowSize(this->window, width, height);
}

SDL_Renderer* Game::getRenderer() const {
    return this->renderer;
}

bool Game::isRunning() const {
    return this->running;
}

void Game::quit() {
    this->running = false;
}

Game* Game::instance;