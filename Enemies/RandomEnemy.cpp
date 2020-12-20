//
// Created by levymaty on 18.12.20.
//

#include "RandomEnemy.h"

RandomEnemy::RandomEnemy(Coordinates coords, Player *player) : Enemy(coords, player) {
    this->colorCode = 35;
}
