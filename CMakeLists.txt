cmake_minimum_required(VERSION 3.28.1)

project(main)

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/lib/SDL2)

add_executable(main
            ./src/main.c
            ./src/game/player.c)

target_link_libraries(main SDL2)
