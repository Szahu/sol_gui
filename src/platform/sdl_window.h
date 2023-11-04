#pragma once
#include "./../window.h"
#include <SDL.h>
#include <imgui.h>

class WindowSdlImpl : public Window {
public:
    WindowSdlImpl() {}

    virtual void Init(const WindowConfig& config);
    virtual void StartFrame();
    virtual void EndFrame();
    virtual void Destroy();
    virtual const bool ShouldClose() const;

private:
    SDL_Window* m_window = nullptr;
    bool m_close = false;
    SDL_GLContext m_gl_context;
    static constexpr ImVec4 CLEAR_COLOR = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
};