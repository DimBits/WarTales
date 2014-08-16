#include "ObjectManager.h"
#include "DrawableObject.h"
#include "Player.h"
#include <iostream>

ObjectManager::ObjectManager() {
    this->objects.insert(std::make_pair(1, new Player));
    auto ptr = dynamic_cast<DrawableObject*>(this->objects[1]);
    if (ptr != nullptr) {
        ptr->load("Resources/debug/rider.bmp");
    }
}

void ObjectManager::processEvent(SDL_Event& event) {
    for (auto pair : this->objects) {
        EventProcessingObject* ptr = dynamic_cast<EventProcessingObject*> (pair.second);
        if (ptr != nullptr) {
            ptr->processEvent(event);
        }
    }
}

void ObjectManager::render() {
    for (auto pair : this->objects) {
        DrawableObject* ptr = dynamic_cast<DrawableObject*> (pair.second);
        if (ptr != nullptr) {
            ptr->draw();
        }
    }
}