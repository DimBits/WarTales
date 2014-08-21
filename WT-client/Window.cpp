#include "Window.h"
#include "Renderer.h"
#include "Surface.h"

Window::Window()
    : Window(DEFAULT::WINDOW_TITLE,
        DEFAULT::WINDOW_POSITION.x,
        DEFAULT::WINDOW_POSITION.y,
        DEFAULT::WINDOW_POSITION.w,
        DEFAULT::WINDOW_POSITION.h,
        DEFAULT::WINDOW_FLAGS) {
}

Window::Window(const char* title, int32_t x, int32_t y, int32_t width, int32_t height, uint32_t flags) {
    this->window = SDL_CreateWindow(title, x, y, width, height, flags);
    if (this->window == nullptr) {
        SDL_Log(SDL_GetError());
    }
}

Window::~Window() {
    SDL_DestroyWindow(this->window);
}

void Window::processEvent(SDL_Event& event) {
    switch (event.window.type) {
        case SDL_WINDOWEVENT_SHOWN:
            this->onShow(event);
            break;
        case SDL_WINDOWEVENT_HIDDEN:
            this->onHide(event);
            break;
        case SDL_WINDOWEVENT_EXPOSED:
            this->onExpose(event);
            break;
        case SDL_WINDOWEVENT_MOVED:
            this->onMove(event);
            break;
        case SDL_WINDOWEVENT_RESIZED:
            this->onResize(event);
            break;
        case SDL_WINDOWEVENT_MINIMIZED:
            this->onMinimize(event);
            break;
        case SDL_WINDOWEVENT_MAXIMIZED:
            this->onMaximize(event);
            break;
        case SDL_WINDOWEVENT_RESTORED:
            this->onRestore(event);
            break;
        case SDL_WINDOWEVENT_ENTER:
            this->onMouseEnter(event);
            break;
        case SDL_WINDOWEVENT_LEAVE:
            this->onMouseLeave(event);
            break;
        case SDL_WINDOWEVENT_FOCUS_GAINED:
            this->onFocusGaine(event);
            break;
        case SDL_WINDOWEVENT_FOCUS_LOST:
            this->onFocusLost(event);
            break;
        case SDL_WINDOWEVENT_CLOSE:
            this->onClose(event);
            break;
    }
}

Renderer* Window::getRenderer() const {
    return new Renderer(SDL_GetRenderer(this->window));
}

uint32_t Window::getID() const {
    return SDL_GetWindowID(this->window);
}

Size Window::getMaximumSize() const {
    Size maxSize;
    SDL_GetWindowMaximumSize(this->window, &maxSize.rw(), &maxSize.rh());
    return maxSize;
}

Size Window::getMinimumSize() const {
    Size minSize;
    SDL_GetWindowMinimumSize(this->window, &minSize.rw(), &minSize.rh());
    return minSize;
}

uint32_t Window::getPixelFormat() const {
    uint32_t pixelFormat = SDL_GetWindowPixelFormat(this->window);
    if (pixelFormat == SDL_PIXELFORMAT_UNKNOWN) {
        SDL_Log(SDL_GetError());
    }
    return pixelFormat;
}

SDL_Point Window::getPosition() const {
    SDL_Point position;
    SDL_GetWindowPosition(this->window, &position.x, &position.y);
    return position;
}

Size Window::getSize() const {
    Size size;
    SDL_GetWindowSize(this->window, &size.rw(), &size.rh());
    return size;
}

Surface* Window::getSurface() const {
    SDL_Surface* surface = SDL_GetWindowSurface(this->window);
    if (surface == nullptr) {
        SDL_Log(SDL_GetError());
    }
    return new Surface(surface);
}

const char* Window::getTitle() const {
    return SDL_GetWindowTitle(this->window);
}

void Window::hide() {
    SDL_HideWindow(this->window);
}

void Window::maximize() {
    SDL_MaximizeWindow(this->window);
}

void Window::minimize() {
    SDL_MinimizeWindow(this->window);
}

void Window::raise() {
    SDL_RaiseWindow(this->window);
}

void Window::restore() {
    SDL_RestoreWindow(this->window);
}

void Window::setBordered(bool state) {
    SDL_bool sdlState = SDL_FALSE;
    if (state) {
        sdlState = SDL_TRUE;
    }
    SDL_SetWindowBordered(this->window, sdlState);
}

void Window::setBrightness(float brightness) {
    if (SDL_SetWindowBrightness(this->window, brightness)) {
        SDL_Log(SDL_GetError());
    }
}

float Window::getBrightness() const {
    SDL_GetWindowBrightness(this->window);
}

uint32_t Window::getFlags() const {
    return SDL_GetWindowFlags(this->window);
}

void Window::setFullscreen() {
    if (SDL_SetWindowFullscreen(this->window, SDL_WINDOW_FULLSCREEN)) {
        SDL_Log(SDL_GetError());
    }
}

void Window::setGammaRamp(uint16_t red, uint16_t green, uint16_t blue) {
    if (SDL_SetWindowGammaRamp(this->window, &red, &green, &blue)) {
        SDL_Log(SDL_GetError());
    }
}

void Window::getGammaRamp(uint16_t& red, uint16_t& green, uint16_t& blue) const {
    if (SDL_GetWindowGammaRamp(this->window, &red, &green, &blue)) {
        SDL_Log(SDL_GetError());
    }
}

bool Window::getGrab() const {
    SDL_bool state = SDL_GetWindowGrab(this->window);
    if (state == SDL_TRUE) {
        return true;
    } else {
        return false;
    }
}

void Window::setGrab(bool state) {
    SDL_bool grabbed = SDL_FALSE;
    if (state) {
        grabbed = SDL_TRUE;
    }
    SDL_SetWindowGrab(this->window, grabbed);
}

void Window::setIcon(const Surface* icon) {
    SDL_SetWindowIcon(this->window, icon->surface);
}

void Window::setMaximumSize(const Size& maxSize) {
    SDL_SetWindowMaximumSize(this->window, maxSize.width(), maxSize.height());
}

void Window::setMinimumSize(const Size& minSize) {
    SDL_SetWindowMinimumSize(this->window, minSize.width(), minSize.height());
}

void Window::setPosition(const SDL_Point& position) {
    SDL_SetWindowPosition(this->window, position.x, position.y);
}

void Window::setSize(const Size& size) {
    SDL_SetWindowSize(this->window, size.width(), size.height());
}

void Window::setTitle(const char* title) {
    SDL_SetWindowTitle(this->window, title);
}

void Window::show() {
    SDL_ShowWindow(this->window);
}

void Window::render() {
    SDL_UpdateWindowSurface(this->window);
}

void Window::renderParts(std::vector<SDL_Rect>& parts) {
    if (SDL_UpdateWindowSurfaceRects(this->window, parts.data(), parts.size())) {
        SDL_Log(SDL_GetError());
    }
}