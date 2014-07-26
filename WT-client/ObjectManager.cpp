#include "ObjectManager.h"
#include "DrawableObject.h"

ObjectManager::~ObjectManager() {
}

void ObjectManager::render() {
    for (Object* obj : this->objects) {
        DrawableObject* ptr = dynamic_cast<DrawableObject*> (obj);
        if (ptr != nullptr) {
            ptr->draw();
        }
    }
}