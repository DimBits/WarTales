#include "InputReactingObject.h"

void InputReactingObject::processEvent(SDL_Event& event) {
    MouseReactingObject::processEvent(event);
    KeyboardReactingObject::processEvent(event);
}