#pragma once

class Window {
public:

    struct WindowConfig {
        unsigned int width;
        unsigned int height;
    };

    virtual void Init(const WindowConfig& config) = 0;
    virtual void StartFrame() = 0;
    virtual void EndFrame() = 0;
    virtual void Destroy() = 0;
    virtual const bool ShouldClose() const = 0;
    virtual ~Window() {}
};