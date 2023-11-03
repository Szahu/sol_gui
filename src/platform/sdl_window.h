#pragma once
#include "./../window.h"
#include "SDL.h"

class WindowSdlImpl : public Window {
public:

    virtual void Init(const WindowConfig& config);
    virtual void StartFrame();
    virtual void EndFrame();
    virtual void Destroy();
    virtual const bool ShouldClose() const;

private:
    SDL_Window* m_window = nullptr;
    SDL_Renderer* m_renderer = nullptr;
    bool m_close = false;
};