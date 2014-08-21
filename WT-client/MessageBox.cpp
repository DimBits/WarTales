#include "MessageBox.h"

MessageBox::~MessageBox() {
}

/*
 void Window::showMessageBox(const char* title, const char* text, SDL_MessageBoxFlags flags) {
    SDL_MessageBoxButtonFlags;
    SDL_MessageBoxColorScheme scheme;/*
    scheme[SDL_MESSAGEBOX_COLOR_BACKGROUND]
    scheme[SDL_MESSAGEBOX_COLOR_TEXT]
    scheme[SDL_MESSAGEBOX_COLOR_BUTTON_BORDER]
    scheme[SDL_MESSAGEBOX_COLOR_BUTTON_BACKGROUND]
    scheme[SDL_MESSAGEBOX_COLOR_BUTTON_SELECTED]
    SDL_MessageBoxButtonData buttonData;
    buttonData.flags = SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT;
    //buttonData.buttonid = ;
    buttonData.text = "OK";
    SDL_MessageBoxColor color;
    SDL_MessageBoxData data;
    //data.flags = ;
    data.title = title;
    data.message = text;
    data.window = this->window;
    if (!SDL_ShowMessageBox()) {
        SDL_Log(SDL_GetError());
    }
}*/