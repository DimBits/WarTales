#ifndef GAME_H
#define	GAME_H

#include <SDL.h>
#include <string>
#include "ObjectManager.h"
#include "Noncopyable.h"
#include "wt-client.h"

class Game final : public Noncopyable {
public:
    Game();
    ~Game();
    static Game* getInstance();
    SDL_Window* getWindow() const;
    SDL_Renderer* getRenderer() const;
    const SDL_Rect& getPosition() const;
    bool isRunning() const;
    const std::string& getTitle() const;
    void setTitle(const std::string& title);
    void setRenderDrawColor(const SDL_Color& color);
    void quit();
    void exec();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Rect position = wt::DEFAULT::GAME_WINDOW_POSITION;
    SDL_Color renderDrawColor = wt::DEFAULT::GAME_RENDER_DRAW_COLOR;
    bool fullscreenEnable = wt::DEFAULT::GAME_WINDOW_FULLSCREEN_ENABLE;
    std::string title = wt::DEFAULT::GAME_WINDOW_TITLE;
    ObjectManager objectManager;
    bool running;
    static Game* instance;
    void render();
    void processEvents();
    void onQuit();
};

#endif	/* GAME_H */

