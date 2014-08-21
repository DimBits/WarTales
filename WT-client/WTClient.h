#ifndef WTCLIENT_H
#define	WTCLIENT_H

#include <SDL.h>
#include "Noncopyable.h"

class Window;
class Renderer;
class ObjectManager;

class WTClient final : public Noncopyable {
public:
    WTClient();
    virtual ~WTClient();
    static WTClient* getInstance();
    void exec();
private:
    void render();
    void processEvent(const SDL_Event& event);
    Window* window;
    Renderer* renderer;
    ObjectManager* objectManager;
    bool running;
};

#endif	/* WTCLIENT_H */

