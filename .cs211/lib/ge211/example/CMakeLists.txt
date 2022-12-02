cmake_minimum_required(VERSION 3.13)
project(ge211_examples CXX)

if(NOT GE211_INHERITED)
    find_package(Ge211 2021.1 REQUIRED)
endif()

add_executable(fireworks fireworks.cxx ../../../../src/dot.cxx ../../../../src/dot.hxx ../../../../src/dots.cxx ../../../../src/dots.hxx ../../../../src/walls.cxx ../../../../src/walls.hxx ../../../../src/player.cxx ../../../../src/player.hxx ../../../../src/red_ghost.cxx ../../../../src/red_ghost.hxx ../../../../src/endgame.cxx ../../../../src/endgame.hxx ../../../../src/blue_ghost.cxx ../../../../src/blue_ghost.hxx ../../../../src/pink_ghost.cxx ../../../../src/pink_ghost.hxx ../../../../src/orange_ghost.cxx ../../../../src/orange_ghost.hxx)
set_target_properties(fireworks PROPERTIES
        CXX_STANDARD            14
        CXX_STANDARD_REQUIRED   On
        CXX_EXTENSIONS          Off)
target_link_libraries(fireworks ge211)

if(MSVC)
    target_compile_options(fireworks PRIVATE /W4)
else(MSVC)
    target_compile_options(fireworks PRIVATE -Wall -pedantic-errors)
endif(MSVC)

include(GNUInstallDirs)
install(TARGETS fireworks
        RUNTIME DESTINATION bin)
