cmake_minimum_required(VERSION 3.28.1)

project(basic_arcade)

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/lib/SDL2)

add_executable(basic_arcade
            ./src/main.c
            ./src/game/controller.c
            ./src/game/player.c
            ./src/game/projectile.c
            ./src/game/renderer.c)

target_link_libraries(basic_arcade SDL2)
