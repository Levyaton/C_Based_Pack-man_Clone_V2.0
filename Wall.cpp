//
// Created by levyaton on 1/19/21.
//

#include "Wall.h"

Wall::Wall(const Coordinates &coords) : Tile(coords) {
    this->type = WALL;
    this->displayChars = "[]";
}
