//
// Created by levymaty on 18.12.20.
//

#include "Enemy.h"

Enemy::Enemy(Coordinates coords, Player* player) : Tile(coords) {
    this->displayChars = "SS";
    this->player = player;
    this->type = ENEMY;
}

int Enemy::getColorCode() const {
    return this->colorCode;
}
