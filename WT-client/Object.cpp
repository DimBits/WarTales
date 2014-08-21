#include "Object.h"

void Object::processEvent(const SDL_Event& event) {
    if (this->eventHandlerMap.find(event.type) != this->eventHandlerMap.end()) {
        this->eventHandlerMap[event.type](event);
    }
}

void Object::removeEventHandler(SDL_EventType eventType) {
    this->eventHandlerMap.erase(eventType);
}