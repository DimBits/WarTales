#ifndef PLAYER_H
#define	PLAYER_H

#include "DrawableObject.h"
#include "InputReactingObject.h"

class Player final : virtual public DrawableObject, virtual public InputReactingObject {
public:
    Player();
    virtual ~Player() {}
    void onMouseMove(SDL_Event& event) override;
    void onMouseButtonDown(SDL_Event& event) override;
    void onMouseButtonUp(SDL_Event& event) override;
    void onMouseWheel(SDL_Event& event) override;
    void onKeyDown(SDL_Event& event) override;
    void onKeyUp(SDL_Event& event) override;
};

#endif	/* PLAYER_H */

