#ifndef MOUSEREACTINGOBJECT_H
#define	MOUSEREACTINGOBJECT_H

#include "EventProcessingObject.h"

class MouseReactingObject : virtual public EventProcessingObject {
public:
    virtual ~MouseReactingObject() {}
    void processEvent(SDL_Event& event) override;
protected:
    virtual void onMouseMove(SDL_Event& event) {}
    virtual void onMouseButtonDown(SDL_Event& event) {}
    virtual void onMouseButtonUp(SDL_Event& event) {}
    virtual void onMouseWheel(SDL_Event& event) {}
};

#endif	/* MOUSEREACTINGOBJECT_H */

