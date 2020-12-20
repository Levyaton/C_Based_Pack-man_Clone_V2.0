//
// Created by levymaty on 18.12.20.
//

#ifndef PAC_MAN_ENEMY_H
#define PAC_MAN_ENEMY_H


#include "Tile.h"
#include "Player.h"
#include "Map.h"


class Enemy: public Tile {

protected:
    Player* player;
    int colorCode{};
public:
    enum Direction{
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
    Enemy(Coordinates coords, Player* player);
    int getColorCode() const;
    virtual Coordinates move(Player player, Map map);
};


#endif //PAC_MAN_ENEMY_H
