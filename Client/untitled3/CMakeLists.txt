cmake_minimum_required(VERSION 3.21)
project(untitled3 C)


set(CMAKE_C_STANDARD 99)
set(SDL2_INCLUDE_DIR SDL2-2.0.20/include)
set(SDL2_LIBRARY_DIR SDL2-2.0.20/lib/x64)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIBRARY_DIR})

add_executable(untitled3 main.c cmake-build-debug/Constantes.h pantalla.c pantalla.h)
target_link_libraries(${PROJECT_NAME} SDL2main SDL2)

