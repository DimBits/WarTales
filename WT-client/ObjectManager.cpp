#include "ObjectManager.h"
#include "Object.h"
#include "Player.h"
#include <iostream>

ObjectManager::ObjectManager() {/*
    this->objects.insert(std::make_pair(1, new Player));
    auto ptr = dynamic_cast<Texture*>(this->objects[1]);
    if (ptr != nullptr) {
        ptr->load("Resources/Textures/grenadier.png");
    }*/
}

void ObjectManager::processEvent(const SDL_Event& event) {/*
    for (auto pair : this->objects) {
        EventProcessingObject* ptr = dynamic_cast<EventProcessingObject*> (pair.second);
        if (ptr != nullptr) {
            ptr->processEvent(event);
        }
    }*/
}

void ObjectManager::render() {/*
    for (auto pair : this->objects) {
        RenderObject* ptr = dynamic_cast<RenderObject*> (pair.second);
        if (ptr != nullptr) {
            ptr->render();
        }
    }*/
}