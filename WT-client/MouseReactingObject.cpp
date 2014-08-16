#include "MouseReactingObject.h"

void MouseReactingObject::processEvent(SDL_Event& event) {
    switch (event.type) {
        case SDL_MOUSEMOTION:
            this->onMouseMove(event);
            break;
        case SDL_MOUSEBUTTONDOWN:
            this->onMouseButtonDown(event);
            break;
        case SDL_MOUSEBUTTONUP:
            this->onMouseButtonUp(event);
            break;
        case SDL_MOUSEWHEEL:
            this->onMouseWheel(event);
            break;
    }
}