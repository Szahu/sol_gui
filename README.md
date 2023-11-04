# sol_gui

A simple wrapper for [imgui](https://github.com/ocornut/imgui/tree/master) using [SDL3](https://github.com/libsdl-org/SDL) and `OpenGL` implementations. 

### Example Setup
Run this to download the code and dependancies:
```bash
git clone https://github.com/Szahu/sol_gui.git
git submodule update --init --recursive
```

Example `CMakeLists.txt`:
```CMake
cmake_minimum_required(VERSION 3.22)

project(test_app)

add_subdirectory(sol_gui)

add_executable(${PROJECT_NAME} main.cc)
target_link_libraries(${PROJECT_NAME} PUBLIC sol_gui)
include_directories(sol_gui/include)
```
Then to build: 

```bash
mkdir build
cd build
cmake ..
cmake --build .
```
Example of `main.cc`:
```cpp
#include "sol_gui.h"

int main(int argc, char** argv) {

    RunSolApplication({600, 400, "window title"}, [] () {
        bool show_demo = true;
        ImGui::ShowDemoWindow(&show_demo);
    });

    return 0;
}
```
