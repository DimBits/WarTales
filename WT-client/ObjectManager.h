#ifndef OBJECTMANAGER_H
#define	OBJECTMANAGER_H

#include <unordered_map>
#include "Noncopyable.h"
#include "EventProcessingObject.h"
#include "Object.h"

class ObjectManager final : public Noncopyable, public EventProcessingObject {
public:
    ObjectManager();
    virtual ~ObjectManager() {}
    void processEvent(SDL_Event& event) override;
    void render();
private:
    std::unordered_map<uint32_t, Object*> objects;
};

#endif	/* OBJECTMANAGER_H */

