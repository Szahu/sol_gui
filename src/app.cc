#include "app.h"
#include <memory>

void RunSolApplication(const Window::WindowConfig& config, std::function<void()> app_loop) {
    auto window = std::shared_ptr<Window>(new WindowSdlImpl);
    window->Init(config);

    while (!window->ShouldClose()) {
        window->StartFrame();

        app_loop();

        window->EndFrame();
    }

    window->Destroy();
}