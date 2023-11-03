cmake_minimum_required(VERSION 3.22)

project(sol_gui)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(VENDOR_DIR ${CMAKE_SOURCE_DIR}/vendor)

# Add source files
file(GLOB_RECURSE SRC_FILES 
	${CMAKE_SOURCE_DIR}/src/*.c
	${CMAKE_SOURCE_DIR}/src/*.cc
	${CMAKE_SOURCE_DIR}/src/*.cpp
	${CMAKE_SOURCE_DIR}/src/platform*.c
	${CMAKE_SOURCE_DIR}/src/platform*.cc
	${CMAKE_SOURCE_DIR}/src/platform*.cpp)
	
# Add header files
file(GLOB_RECURSE HDR_FILES 
	${CMAKE_SOURCE_DIR}/src/*.h
	${CMAKE_SOURCE_DIR}/src/*.hpp
	${CMAKE_SOURCE_DIR}/src/platform/*.h
	${CMAKE_SOURCE_DIR}/src/platform/*.hpp)

# SDL3
set(SDL_TEST OFF)
add_subdirectory(${VENDOR_DIR}/SDL)

# Entry point
add_executable(${PROJECT_NAME} ${SRC_FILES} ${HDR_FILES})

include_directories(${VENDOR_DIR}/SDL/include)
target_link_libraries(${PROJECT_NAME} SDL3::SDL3)

# compiler flags windows
if (WIN32)
	target_compile_options(${PROJECT_NAME} PUBLIC "/Wall")
endif (WIN32)

# compiler flags linux
if (UNIX)
	target_compile_options(gb_emulator PUBLIC "-wall" "-O2")
endif (UNIX)