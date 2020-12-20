cmake_minimum_required(VERSION 3.17)
project(PaC___Man)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PaC___Man
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
        Map.h)
