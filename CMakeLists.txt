cmake_minimum_required(VERSION 3.21)

project(Tetris VERSION 0.3.1 LANGUAGES C)

option(TETRIS_WINDOWED_SUBSYSTEM "Build without a console window on Windows." ON)
option(TETRIS_STATIC_MSVC_RUNTIME "Link the MSVC runtime statically." ON)
option(TETRIS_INSTALL_RUNTIME_DEPENDENCIES "Install runtime shared-library dependencies where supported." ON)
set(TETRIS_ASSET_DIR "" CACHE PATH "Directory containing runtime assets to include in install/package output.")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/modules")

set(TETRIS_SOURCES
        animation.c
        colors.c
        events.c
        graphics.c
        logic.c
        logic_event_handlers.c
        main.c
        main_menu.c
        menu.c
        pieces.c
        randomizer.c
        rendering.c
        rendering_utilities.c
        settings.c
        settings_menu.c
        sound.c
        text.c
        )

add_executable(Tetris ${TETRIS_SOURCES})

target_compile_features(Tetris PRIVATE c_std_99)
set_target_properties(Tetris PROPERTIES
        C_STANDARD 99
        C_STANDARD_REQUIRED YES
        C_EXTENSIONS NO
        )

if (WIN32 AND TETRIS_WINDOWED_SUBSYSTEM)
    set_target_properties(Tetris PROPERTIES WIN32_EXECUTABLE YES)
endif ()

if (MSVC AND TETRIS_WINDOWED_SUBSYSTEM)
    target_link_options(Tetris PRIVATE /ENTRY:mainCRTStartup)
endif ()

if (MSVC AND TETRIS_STATIC_MSVC_RUNTIME)
    set_property(TARGET Tetris PROPERTY
            MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif ()

target_compile_definitions(Tetris PRIVATE SDL_MAIN_HANDLED)

find_package(SDL2 CONFIG QUIET)
find_package(SDL2_ttf CONFIG QUIET)
find_package(SDL2_mixer CONFIG QUIET)

if (SDL2_FOUND AND SDL2_ttf_FOUND AND SDL2_mixer_FOUND)
    target_link_libraries(Tetris PRIVATE
            $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
            $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
            $<IF:$<TARGET_EXISTS:SDL2_ttf::SDL2_ttf>,SDL2_ttf::SDL2_ttf,SDL2_ttf::SDL2_ttf-static>
            $<IF:$<TARGET_EXISTS:SDL2_mixer::SDL2_mixer>,SDL2_mixer::SDL2_mixer,SDL2_mixer::SDL2_mixer-static>
            )
else ()
    find_package(PkgConfig QUIET)

    if (PkgConfig_FOUND)
        pkg_check_modules(SDL2_PKG QUIET IMPORTED_TARGET sdl2)
        pkg_check_modules(SDL2_TTF_PKG QUIET IMPORTED_TARGET SDL2_ttf)
        pkg_check_modules(SDL2_MIXER_PKG QUIET IMPORTED_TARGET SDL2_mixer)
    endif ()

    if (SDL2_PKG_FOUND AND SDL2_TTF_PKG_FOUND AND SDL2_MIXER_PKG_FOUND)
        target_link_libraries(Tetris PRIVATE
                PkgConfig::SDL2_PKG
                PkgConfig::SDL2_TTF_PKG
                PkgConfig::SDL2_MIXER_PKG
                )
    else ()
        find_package(SDL2 REQUIRED)
        find_package(SDL2_ttf REQUIRED)
        find_package(SDL2_mixer REQUIRED)

        target_include_directories(Tetris PRIVATE
                ${SDL2_INCLUDE_DIR}
                ${SDL2_TTF_INCLUDE_DIR}
                ${SDL2_MIXER_INCLUDE_DIR}
                )

        target_link_libraries(Tetris PRIVATE
                ${SDL2_LIBRARY}
                ${SDL2_TTF_LIBRARY}
                ${SDL2_MIXER_LIBRARY}
                )
    endif ()
endif ()

if (WIN32 AND TETRIS_INSTALL_RUNTIME_DEPENDENCIES)
    install(TARGETS Tetris
            RUNTIME DESTINATION .
            BUNDLE DESTINATION .
            )

    install(FILES $<TARGET_RUNTIME_DLLS:Tetris>
            DESTINATION .
            )

    if (DEFINED VCPKG_INSTALLED_DIR AND DEFINED VCPKG_TARGET_TRIPLET)
        set(TETRIS_VCPKG_RUNTIME_DIR "${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/bin")

        if (EXISTS "${TETRIS_VCPKG_RUNTIME_DIR}")
            install(DIRECTORY "${TETRIS_VCPKG_RUNTIME_DIR}/"
                    DESTINATION .
                    FILES_MATCHING PATTERN "*.dll"
                    )
        endif ()
    endif ()
else ()
    install(TARGETS Tetris
            RUNTIME DESTINATION .
            BUNDLE DESTINATION .
            )
endif ()

if (TETRIS_ASSET_DIR)
    if (NOT IS_DIRECTORY "${TETRIS_ASSET_DIR}")
        message(FATAL_ERROR "TETRIS_ASSET_DIR does not exist: ${TETRIS_ASSET_DIR}")
    endif ()

    install(DIRECTORY "${TETRIS_ASSET_DIR}/"
            DESTINATION .
            FILES_MATCHING
            PATTERN "*.cfg"
            PATTERN "*.mp3"
            PATTERN "*.ttf"
            PATTERN "*.txt"
            )
endif ()

set(CPACK_PACKAGE_NAME "Tetris")
set(CPACK_PACKAGE_VENDOR "AvihooI")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY OFF)
set(CPACK_PACKAGE_FILE_NAME "Tetris-${PROJECT_VERSION}-${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_PROCESSOR}")

if (WIN32)
    set(CPACK_GENERATOR "ZIP")
else ()
    set(CPACK_GENERATOR "TGZ")
endif ()

include(CPack)
