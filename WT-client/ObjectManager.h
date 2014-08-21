#ifndef OBJECTMANAGER_H
#define	OBJECTMANAGER_H

#include <SDL_events.h>
#include <unordered_map>
#include "Noncopyable.h"

class Object;

class ObjectManager final : public Noncopyable {
public:
    ObjectManager();
    virtual ~ObjectManager() {}
    void processEvent(const SDL_Event& event) ;
    void render();
private:
    std::unordered_map<uint32_t, Object*> objects;
};

#endif	/* OBJECTMANAGER_H */

