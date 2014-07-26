#ifndef DRAWABLEOBJECT_H
#define	DRAWABLEOBJECT_H

#include "Object.h"
#include <SDL_render.h>
#include <string>

class DrawableObject : virtual public Object {
public:
    DrawableObject(SDL_Renderer* const renderer);
    void draw() const;
    void load(const std::string& fileName);
private:
    SDL_Texture* texture;
    SDL_Renderer* const renderer;
    SDL_Point pos;
};

#endif	/* DRAWABLEOBJECT_H */

