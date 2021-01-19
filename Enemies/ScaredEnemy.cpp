//
// Created by levymaty on 18.12.20.
//

#include "ScaredEnemy.h"

ScaredEnemy::ScaredEnemy(Coordinates coords, Player *player) : Enemy(coords, player) {
    this->colorCode = 34;
    this->type = SCAREDENEMY;
}
