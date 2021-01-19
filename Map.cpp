//
// Created by levymaty on 18.12.20.
//

#include "Map.h"

Map::Map(Tile **tiles, int width, int height) {
    this->tiles = tiles;
    this->height = height;
    this->width = width;
}

Tile Map::getTile(Coordinates coords) {
    return tiles[coords.y][coords.x];
}

void Map::swapTile(Coordinates dest, const Tile& sourceTile) {
    Tile &chosen = tiles[dest.y][dest.x];
    bool chosenHasPoint = chosen.hasPoint();
    bool sourceHasPoint = sourceTile.hasPoint();

    tiles[sourceTile.getCoords().y][sourceTile.getCoords().x] = chosen;


    tiles[dest.y][dest.x] = sourceTile;
}

int Map::getWidth() const {
    return this->width;
}

int Map::getHeight() const {
    return this->height;
}
