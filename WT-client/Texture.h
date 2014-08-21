#ifndef TEXTURE_H
#define	TEXTURE_H

#include "wt.h"
#include <SDL_render.h>
#include "Noncopyable.h"

class Renderer;
class Surface;

class Texture : public Noncopyable {
public:
    Texture(SDL_Texture* texture);
    Texture(const Renderer* renderer, const Surface* surface);
    virtual ~Texture();
    uint8_t getAlphaMod() const;
    SDL_BlendMode getBlendMode() const;
    SDL_Color getColorMod() const;
    Size getSize() const;
    void setBlendMode(const SDL_BlendMode& blendMode);
    void setColorMod(const SDL_Color& color);
private:
    SDL_Texture* texture;
    friend class Renderer;
};

#endif	/* TEXTURE_H */

