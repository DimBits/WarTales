#ifndef MOUSEREACTINGOBJECT_H
#define	MOUSEREACTINGOBJECT_H

#include "EventProcessingObject.h"

class MouseReactingObject : public EventProcessingObject {
public:
    void processEvent(SDL_Event event) override;
protected:
    virtual void onMouseMove(SDL_Event& event) = 0;
    virtual void onMouseButtonDown(SDL_Event& event) = 0;
    virtual void onMouseButtonUp(SDL_Event& event) = 0;
};

#endif	/* MOUSEREACTINGOBJECT_H */

