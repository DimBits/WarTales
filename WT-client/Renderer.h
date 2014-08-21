#ifndef RENDERER_H
#define	RENDERER_H

#include <SDL_render.h>
#include <vector>
#include "Noncopyable.h"
#include "wt.h"

class Window;
class Texture;

class Renderer : public Noncopyable {
public:
    Renderer(SDL_Renderer* renderer);
    Renderer(const Window* window);
    virtual ~Renderer();
    SDL_BlendMode getDrawBlendMode() const;
    SDL_Color getDrawColor() const;
    Texture* getTarget() const;
    SDL_Rect getClipRect() const;
    Size getLogicalSize() const;
    Size getOutputSize() const;
    Scale getScale() const;
    SDL_Rect getViewport() const;
    bool isTargetSupported() const;
    void setDrawBlendMode(const SDL_BlendMode& blendMode);
    void setTarget(const Texture* target);
    void setDrawColor(const SDL_Color& drawColor);
    void setClipRect(const SDL_Rect* rect);
    void setLogicalSize(const Size& size);
    void setScale(const Scale& scale);
    void setViewport(const SDL_Rect* rect);
    void present();
    void clear();
    void drawTexture(const Texture* texture, const SDL_Rect* srcRect, const SDL_Rect* dstRect);
    void drawTexture(const Texture* texture, const SDL_Rect* srcRect, const SDL_Rect* dstRect, double degrees, const SDL_Point* center, const SDL_RendererFlip flip);
    void drawLine(const SDL_Point& x1, const SDL_Point& x2);
    void drawLines(const std::vector<SDL_Point>& points);
    void drawPoint(const SDL_Point& point);
    void drawPoints(const std::vector<SDL_Point>& points);
    void drawRect(const SDL_Rect* rect);
    void drawRects(const std::vector<SDL_Rect>& rects);
    void fillRect(const SDL_Rect* rect);
    void fillRects(const std::vector<SDL_Rect>& rects);
private:
    SDL_Renderer* renderer;
    friend class Texture;
};

#endif	/* RENDERER_H */

