cmake_minimum_required(VERSION 3.5)

project(game_of_life LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
        main.cpp
        main_gui.cpp
        main_gui.h
        game_of_life.cpp
        game_of_life.h
)

list(APPEND PATHS ${CMAKE_PREFIX_PATH})
list(APPEND PATHS "../../libs/SFML-2.5.1-windows-vc15-64-bit/")

set(CMAKE_PREFIX_PATH ${PATHS})

find_package(SFML 2 REQUIRED network audio graphics window system)

add_executable(game_of_life ${PROJECT_SOURCES})

target_link_libraries(game_of_life sfml-graphics sfml-audio sfml-network sfml-window sfml-system)

set(SFML_DLL_PATH "../../libs/SFML-2.5.1-windows-vc15-64-bit/SFML-2.5.1/bin")

list(APPEND SFML_DLL_LIST "${SFML_DLL_PATH}/sfml-graphics-2.dll"
    "${SFML_DLL_PATH}/sfml-audio-2.dll"
    "${SFML_DLL_PATH}/sfml-window-2.dll"
    "${SFML_DLL_PATH}/sfml-network-2.dll"
    "${SFML_DLL_PATH}/sfml-system-2.dll"
)

foreach(dynlibs ${SFML_DLL_LIST})
    add_custom_command (TARGET game_of_life POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${dynlibs}
        ${CMAKE_BINARY_DIR}
    )
endforeach()

