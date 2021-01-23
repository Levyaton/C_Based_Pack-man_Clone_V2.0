//
// Created by levymaty on 18.12.20.
//

#ifndef PAC___MAN_MAP_H
#define PAC___MAN_MAP_H


#include "Tile.h"
#include "Player.h"
#include "Enemy.h"

class Map {
    Tile** tiles;
    int width;
    int height;
    Player* player;
    std::vector<Enemy*> enemies;


private:
public:
    Map(std::string path);
    Map(Tile **tiles, int width, int height);
    Tile getTile(Coordinates coords);

    int getWidth() const;
    int getHeight() const;

    void swapTile(Coordinates dest, const Tile& sourceTile);
};


#endif //PAC___MAN_MAP_H
