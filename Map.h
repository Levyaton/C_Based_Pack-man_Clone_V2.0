//
// Created by levymaty on 18.12.20.
//

#ifndef PAC___MAN_MAP_H
#define PAC___MAN_MAP_H


#include "Tile.h"

class Map {
    Tile** tiles;
    int width;
    int height;

public:
    Map(Tile **tiles, int width, int height);
    Tile getTile(Coordinates coords);

    int getWidth() const;
    int getHeight() const;

    void swapTile(Coordinates dest, const Tile& sourceTile);
};


#endif //PAC___MAN_MAP_H
