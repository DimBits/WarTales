#include "KeyboardReactingObject.h"

void KeyboardReactingObject::processEvent(SDL_Event& event) {
    switch (event.type) {
        case SDL_KEYDOWN:
            this->onKeyDown(event);
            break;
        case SDL_KEYUP:
            this->onKeyUp(event);
            break;
    }
}