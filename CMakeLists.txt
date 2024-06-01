cmake_minimum_required(VERSION 3.28.1)

project(basic_arcade)

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/lib/SDL2)

add_executable(basic_arcade
            ./src/main.c
            ./src/engine/controller.c
            ./src/engine/player.c
            ./src/engine/projectile.c
            ./src/engine/window.c
            ./src/engine/renderer.c)

target_link_libraries(basic_arcade SDL2)
