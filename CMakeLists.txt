cmake_minimum_required(VERSION 3.22)

project(sol_gui)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(VENDOR_DIR vendor)

# Add source files
file(GLOB_RECURSE SRC_FILES 
	src/*.c
	src/*.cc
	src/*.cpp
	src/platform*.c
	src/platform*.cc
	src/platform*.cpp)
	
# Add header files
file(GLOB_RECURSE HDR_FILES 
	src/*.h
	src/*.hpp
	src/platform/*.h
	src/platform/*.hpp)

# SDL3
set(SDL_TEST OFF)
add_subdirectory(${VENDOR_DIR}/SDL)

# Glad
add_library(GLAD "vendor/glad/src/glad.c")
target_include_directories(GLAD PUBLIC "vendor/glad/include")

# OpenGL
find_package(OpenGL REQUIRED)

# imgui
set(IMGUI_SRC_FILES 
	${VENDOR_DIR}/imgui/imgui.cpp
	${VENDOR_DIR}/imgui/imgui_draw.cpp
	${VENDOR_DIR}/imgui/imgui_demo.cpp
	${VENDOR_DIR}/imgui/imgui_tables.cpp
	${VENDOR_DIR}/imgui/imgui_widgets.cpp
	${VENDOR_DIR}/imgui/backends/imgui_impl_sdl3.cpp
	${VENDOR_DIR}/imgui/backends/imgui_impl_opengl3.cpp)

add_library(${PROJECT_NAME} ${SRC_FILES} ${HDR_FILES} ${IMGUI_SRC_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC src ${VENDOR_DIR}/SDL/include ${VENDOR_DIR}/imgui ${VENDOR_DIR}/imgui/backends ${OPENGL_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC opengl32 GLAD SDL3::SDL3)
