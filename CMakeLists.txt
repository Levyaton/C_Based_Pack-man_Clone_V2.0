cmake_minimum_required(VERSION 3.1)
project(PaC___Man)

set(CMAKE_CXX_FLAGS "-lncurses")
set(CMAKE_CXX_STANDARD 14)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

include_directories(.)

add_executable(PaC___Man
        Map.txt
        Enemy.cpp
        Enemy.h
        main.cpp
        main.h
        Tile.cpp
        Tile.h
        Enemies
        Player.h
        Player.cpp
        Map.cpp
        Map.h
        Enemies/AggressiveEnemy.cpp
        Enemies/AggressiveEnemy.h
        Enemies/ScaredEnemy.cpp
        Enemies/ScaredEnemy.h
        Enemies/RandomEnemy.cpp
        Enemies/RandomEnemy.h
        Empty.cpp
        Empty.h
        Wall.cpp
        Wall.h
        )

target_link_libraries(PaC___Man ${CURSES_LIBRARIES})