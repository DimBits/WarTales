#ifndef GAME_H
#define	GAME_H

#include <SDL.h>
#include <string>
#include "ObjectManager.h"
#include "Noncopyable.h"
#include "EventProcessingObject.h"
#include "wt-client.h"

class Game final : public Noncopyable, public EventProcessingObject {
public:
    Game();
    virtual ~Game();
    static Game* getInstance();
    SDL_Window* getWindow() const;
    SDL_Renderer* getRenderer() const;
    void setSize(int32_t width, int32_t height);
    void getSize(int32_t& width, int32_t& height) const;
    bool isRunning() const;
    const char* getTitle() const;
    void setTitle(const char* title);
    void setRenderDrawColor(const SDL_Color& color);
    void setWindowFlags(const uint32_t flags);
    void quit();
    void exec();
    void processEvent(SDL_Event& event) override;
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    ObjectManager* objectManager;
    static Game* instance;
    uint32_t flags = wt::DEFAULT::GAME_WINDOW_FLAGS;
    SDL_Color renderDrawColor = wt::DEFAULT::GAME_RENDER_DRAW_COLOR;
    bool running;
    void render();
    void processEvents();
    void onQuit();
};

#endif	/* GAME_H */

