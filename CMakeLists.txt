cmake_minimum_required(VERSION 3.16)
project(Tetris C)

set(CMAKE_C_STANDARD 99)

set(SDL2_PATH $ENV{SDL2})

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})

add_executable(${PROJECT_NAME} main.c events.c rendering.c logic.c logic.h logic_pieces.c)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})