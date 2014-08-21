#include "wt.h"
#include "WTClient.h"
#include "ObjectManager.h"
#include "Window.h"
#include "Renderer.h"
#include <iostream>

WTClient::WTClient() {
    if (SDL_Init(SDL_INIT_EVERYTHING)) {
        SDL_Log(SDL_GetError());
    }
    this->window = new Window;
    this->renderer = new Renderer(this->window);
    this->objectManager = new ObjectManager;
}

WTClient::~WTClient() {
    delete this->objectManager;
    delete this->renderer;
    delete this->window;
    SDL_Quit();
}

void WTClient::exec() {
    this->running = true;
    uint32_t frameStart, frameTime;
    while (this->running) {
        frameStart = SDL_GetTicks();
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            this->processEvent(event);
        }
        this->render();
        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < DEFAULT::LOOP_TIMEOUT) {
            SDL_Delay(static_cast<uint32_t>(DEFAULT::LOOP_TIMEOUT - frameTime));
        }
    }
}

void WTClient::processEvent(const SDL_Event& event) {
    switch (event.type) {
        case SDL_QUIT:
            this->running = false;
            break;
        default:
            this->objectManager->processEvent(event);
            break;
    }
}

void WTClient::render() {
    this->renderer->clear();
    this->objectManager->render();
    this->renderer->present();
}