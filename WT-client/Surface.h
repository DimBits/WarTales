#ifndef SURFACE_H
#define	SURFACE_H

#include <SDL_surface.h>
#include <vector>
#include "Noncopyable.h"
#include "wt.h"

class Surface : public Noncopyable {
public:
    Surface(SDL_Surface* surface);
    Surface(const Size& size);
    Surface(const char* filePath);
    virtual ~Surface();
    void blitScaled(const Surface* dst, const SDL_Rect* srcRect, SDL_Rect* dstRect);
    void blit(const Surface* dst, const SDL_Rect* srcRect, SDL_Rect* dstRect);
    void fillRect(const SDL_Rect* rect, const SDL_Color& color);
    void fillRects(const std::vector<SDL_Rect>& rects, const SDL_Color& color);
    SDL_Rect getClipRect() const;
    SDL_Color getColorKey() const;
    uint8_t getAlphaMod() const;
    SDL_BlendMode getBlendMode() const;
    SDL_Color getColorMod() const;
    void setColorKey(const SDL_Color& color, bool state);
    bool setClipRect(const SDL_Rect* rect);
    void setAlphaMod(uint8_t alpha);
    void setBlendMode(const SDL_BlendMode& blendMode);
    void setColorMod(const SDL_Color& color);;
private:
    SDL_Surface* surface;
    friend class Texture;
    friend class Window;
};

#endif	/* SURFACE_H */

