#ifndef OBJECT_H
#define	OBJECT_H

#include <SDL_events.h>
#include <unordered_map>
#include <functional>
#include "ObjectManager.h"

class Object {
public:
    virtual ~Object() {}
    template<typename Class, typename ClassMemberFunction>
    void setEventHandler(SDL_EventType eventType, const Class& object, const ClassMemberFunction& function) {
        std::function<void(const SDL_Event&)> eventHandler = std::bind(function, object, std::placeholders::_1);
        this->eventHandlerMap[eventType] = eventHandler;
    }
    void setEventHandler(SDL_EventType eventType, void (*const function)(const SDL_Event&)) {
        this->eventHandlerMap[eventType] = function;
    }
    void removeEventHandler(SDL_EventType eventType);
private:
    void processEvent(const SDL_Event& event);
    std::unordered_map<uint32_t, std::function<void(const SDL_Event&)>> eventHandlerMap;
    friend void ObjectManager::processEvent(const SDL_Event& event);
};

#endif	/* OBJECT_H */

