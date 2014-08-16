#ifndef INPUTREACTINGOBJECT_H
#define	INPUTREACTINGOBJECT_H

#include "MouseReactingObject.h"
#include "KeyboardReactingObject.h"

class InputReactingObject : public MouseReactingObject, public KeyboardReactingObject {
public:
    virtual ~InputReactingObject() {}
    void processEvent(SDL_Event& event) override;
};

#endif	/* INPUTREACTINGOBJECT_H */

