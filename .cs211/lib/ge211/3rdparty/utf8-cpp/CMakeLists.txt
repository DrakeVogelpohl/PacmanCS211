cmake_minimum_required(VERSION 3.13)
project(utf8-cpp CXX)

add_library(utf8-cpp INTERFACE ../../../../../src/dot.cxx ../../../../../src/dot.hxx ../../../../../src/dots.cxx ../../../../../src/dots.hxx ../../../../../src/walls.cxx ../../../../../src/walls.hxx ../../../../../src/player.cxx ../../../../../src/player.hxx ../../../../../src/red_ghost.cxx ../../../../../src/red_ghost.hxx ../../../../../src/endgame.cxx ../../../../../src/endgame.hxx ../../../../../src/blue_ghost.cxx ../../../../../src/blue_ghost.hxx ../../../../../src/pink_ghost.cxx ../../../../../src/pink_ghost.hxx ../../../../../src/orange_ghost.cxx ../../../../../src/orange_ghost.hxx)

target_include_directories(utf8-cpp SYSTEM INTERFACE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)

export(TARGETS utf8-cpp FILE Utf8CppConfig.cmake)
