#ifndef WINDOW_H
#define	WINDOW_H

#include "Object.h"
#include <SDL_video.h>
#include <vector>
#include "Noncopyable.h"
#include "wt.h"

class Surface;
class Renderer;

class Window : public Noncopyable, public Object {
public:
    Window();
    Window(const char* title, int32_t x, int32_t y, int32_t width, int32_t height, uint32_t flags);
    virtual ~Window();
    void processEvent(SDL_Event& event) ;
    Renderer* getRenderer() const;
    uint32_t getID() const;
    Size getSize() const;
    Size getMaximumSize() const;
    Size getMinimumSize() const;
    uint32_t getPixelFormat() const;
    SDL_Point getPosition() const;
    Surface* getSurface() const;
    const char* getTitle() const;
    float getBrightness() const;
    uint32_t getFlags() const;
    bool getGrab() const;
    void getGammaRamp(uint16_t& red, uint16_t& green, uint16_t& blue) const;
    void hide();
    void maximize();
    void minimize();
    void raise();
    void restore();
    void setBordered(bool state);
    void setBrightness(float brightness);
    void setFullscreen();
    void setGammaRamp(uint16_t red, uint16_t green, uint16_t blue);
    void setGrab(bool state);
    void setIcon(const Surface* icon);
    void setMaximumSize(const Size& maxSize);
    void setMinimumSize(const Size& minSize);
    void setPosition(const SDL_Point& position);
    void setSize(const Size& size);
    void setTitle(const char* title);
    void show();
    void render();
    void renderParts(std::vector<SDL_Rect>& parts);
protected:
    virtual void onShow(SDL_Event& event) {}
    virtual void onHide(SDL_Event& event) {}
    virtual void onExpose(SDL_Event& event) {}
    virtual void onMove(SDL_Event& event) {}
    virtual void onResize(SDL_Event& event) {}
    virtual void onMinimize(SDL_Event& event) {}
    virtual void onMaximize(SDL_Event& event) {}
    virtual void onRestore(SDL_Event& event) {}
    virtual void onMouseEnter(SDL_Event& event) {}
    virtual void onMouseLeave(SDL_Event& event) {}
    virtual void onFocusGaine(SDL_Event& event) {}
    virtual void onFocusLost(SDL_Event& event) {}
    virtual void onClose(SDL_Event& event) {}
private:
    SDL_Window* window;
    friend class Renderer;
};

#endif	/* WINDOW_H */

