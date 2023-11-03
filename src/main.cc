#include <iostream>
#include "window.h"
#include "platform/sdl_window.h"
#include <memory>

int main(int argc, char** argv) {

    auto window = std::shared_ptr<Window>(new WindowSdlImpl);

    window->Init({600, 400});
    
    while (!window->ShouldClose()) {
        window->StartFrame();
    }

    window->Destroy();

    return 0;
}