//
// Created by levymaty on 18.12.20.
//

#include "RandomEnemy.h"

RandomEnemy::RandomEnemy(Coordinates coords) : Enemy(coords, nullptr) {
    this->colorCode = 35;
    this->type = RANDOMENEMY;
}
