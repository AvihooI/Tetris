cmake_minimum_required(VERSION 3.16)
project(Tetris C)

set(CMAKE_C_STANDARD 99)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/modules")

#Create a console-less application that has CRT statically linked
if (WIN32 AND MSVC)
    message("WIN32 and MSVC")
    set(SDL2_PATH $ENV{SDL2})
    set(SDL2_TTF_PATH $ENV{SDL2_ttf})
    set(SDL2_MIXER_PATH $ENV{SDL2_mixer})
    add_link_options("/SUBSYSTEM:WINDOWS")
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif ()

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_TTF_INCLUDE_DIR})
include_directories(${SDL2_MIXER_INCLUDE_DIR})

add_executable(${PROJECT_NAME} main.c events.c rendering.c logic.c logic.h pieces.c menu.c main_menu.c settings_menu.c randomizer.c animation.h animation.c settings.c sound.c colors.c pieces.c text.c rendering_utilities.c graphics.c logic_event_handlers.c)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_TTF_LIBRARY} ${SDL2_MIXER_LIBRARY})