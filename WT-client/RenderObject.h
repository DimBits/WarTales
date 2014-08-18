#ifndef RENDEROBJECT_H
#define	RENDEROBJECT_H

#include "Object.h"
#include "wt-client.h"
#include <SDL_render.h>

class RenderObject : virtual public Object {
public:
    RenderObject(SDL_Renderer* const renderer);
    virtual ~RenderObject() {}
    virtual void render();
    void load(const char* imageFileName);
    void setRotationCenter(const SDL_Point& point);
    void setRotationCenter(uint16_t x, uint16_t y);
    void setAngle(float angle);
    void setX(uint16_t x);
    void setY(uint16_t y);
    void setPosition(const SDL_Point& position);
    void setPosition(uint16_t x, uint16_t y);
    void setSourceRectangle(const SDL_Rect& rectangle);
    void setSourceRectangle(uint16_t x, uint16_t y, uint16_t w, uint16_t h);
    void setDestinationRectangle(const SDL_Rect& rectangle);
    void setDestinationRectangle(uint16_t x, uint16_t y, uint16_t w, uint16_t h);
    void setRendererFlip(const SDL_RendererFlip& rendererFlip);
    const SDL_Point getPosition() const;
    const SDL_Point& getRotationCenter() const;
    uint16_t getX() const;
    uint16_t getY() const;
    uint16_t getWidth() const;
    uint16_t getHeight() const;
    double getAngle() const;
private:
    SDL_Renderer* const renderer;
    SDL_Texture* texture;
    SDL_RendererFlip rendererFlip = wt::DEFAULT::RENDERER_FLIP;
    SDL_Rect srcRect, dstRect;
    SDL_Point rotationCenter;
    double rotationAngle;
};

#endif	/* RENDEROBJECT_H */

