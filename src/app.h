#pragma once
#include <functional>
#include "platform/sdl_window.h"

void RunSolApplication(const Window::WindowConfig& config, std::function<void()> app_loop);