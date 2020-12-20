//
// Created by levymaty on 18.12.20.
//


#include "Tile.h"

char Tile::getMapChar() const {
    return mapChar;
}

const std::string &Tile::getDisplayChars() const {
    return displayChars;
}




void Tile::onUpdate() {

}

void Tile::print() {

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

TileType Tile::getType() const {
    return type;
}
