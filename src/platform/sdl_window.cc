#include "sdl_window.h"
#include <iostream>

void WindowSdlImpl::Init(const WindowConfig& config) {
    
    SDL_Init(SDL_INIT_VIDEO);
    SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1");
    SDL_CreateWindowAndRenderer(config.width, config.height, 0, &m_window, &m_renderer);
    SDL_SetWindowSize(m_window, config.width, config.height);
    SDL_SetWindowResizable(m_window, SDL_TRUE);
    SDL_SetWindowPosition(m_window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

}

void WindowSdlImpl::StartFrame() {
    
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        m_close = event.type == SDL_EVENT_QUIT || m_close;
    }
    SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 255);
    SDL_RenderClear(m_renderer);
    SDL_RenderPresent(m_renderer);
}

void WindowSdlImpl::EndFrame() {

}

void WindowSdlImpl::Destroy() {
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

const bool WindowSdlImpl::ShouldClose() const {
    return m_close;
}