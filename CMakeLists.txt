cmake_minimum_required(VERSION 3.16)
project(Tetris C)

set(CMAKE_C_STANDARD 99)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/modules")

#Create a console-less application that has CRT statically linked
if(WIN32 AND MSVC)
    message("WIN32 and MSVC")
    set(SDL2_PATH $ENV{SDL2})
    set(SDL2_TTF_PATH $ENV{SDL2_ttf})
    add_link_options("/SUBSYSTEM:WINDOWS")
    add_compile_options("/MT")
endif()

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf)

include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_TTF_INCLUDE_DIR})

add_executable(${PROJECT_NAME} main.c events.c rendering.c logic.c logic.h logic_pieces.c menu.c)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_TTF_LIBRARY})