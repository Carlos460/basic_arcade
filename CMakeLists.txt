cmake_minimum_required(VERSION 3.28.1)

project(main)

# add_library(sdl SHARED IMPORTED) # or STATIC instead of SHARED
# set_target_properties(sdl PROPERTIES
#   IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/lib/SDL2/libSDL2-2.0.0"
#   INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/include/SDL2"
# )

# add_executable(main ./src/main.c)
# target_link_libraries(main sdl) # also adds the required include path

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/lib/SDL2)

add_executable(main ./src/main.c)
target_link_libraries(main SDL2)
