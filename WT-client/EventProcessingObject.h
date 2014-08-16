#ifndef EVENTPROCESSINGOBJECT_H
#define	EVENTPROCESSINGOBJECT_H

#include "Object.h"
#include <SDL_events.h>

class EventProcessingObject : virtual public Object {
public:
    virtual ~EventProcessingObject() {}
    virtual void processEvent(SDL_Event& event) = 0;
};

#endif	/* EVENTPROCESSINGOBJECT_H */