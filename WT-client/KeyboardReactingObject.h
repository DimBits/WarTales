#ifndef KEYBOARDREACTINGOBJECT_H
#define	KEYBOARDREACTINGOBJECT_H

#include "EventProcessingObject.h"

class KeyboardReactingObject : virtual public EventProcessingObject {
public:
    virtual ~KeyboardReactingObject() {}
    void processEvent(SDL_Event& event) override;
protected:
    virtual void onKeyDown(SDL_Event& event) {}
    virtual void onKeyUp(SDL_Event& event) {}
};

#endif	/* KEYBOARDREACTINGOBJECT_H */

