//
// Created by levymaty on 18.12.20.
//


#include <iostream>
#include "Tile.h"



 std::string &Tile::getDisplayChars()  {
    return displayChars;
}




void Tile::onUpdate() {

}



bool Tile::hasPoint() const{
    return this->containsPoint;
}

const Coordinates &Tile::getCoords() const {
    return coords;
}

void Tile::setCoords(const Coordinates &coords) {
    Tile::coords = coords;
}

bool Tile::isContainsPoint() const {
    return containsPoint;
}

void Tile::setContainsPoint(bool containsPoint) {
    Tile::containsPoint = containsPoint;
}


Tile::Tile(const Coordinates &coords) : coords(coords) {}

int Coordinates::getX() const {
    return x;
}

void Coordinates::setX(int x) {
    Coordinates::x = x;
}

int Coordinates::getY() const {
    return y;
}

void Coordinates::setY(int y) {
    Coordinates::y = y;
}

Coordinates::Coordinates(int x, int y) {
    this->x = x;
    this->y = y;
}

TileType Tile::getType() const {
    return type;
}

int Tile::print(int x, int y) {

    for(int i = 0; i < displayChars.length(); i++){
        mvaddch(y*0.5, x*2+ i, displayChars[i]);
    }
    for(unsigned char c : displayChars){

    }
    return displayChars.length();

}

