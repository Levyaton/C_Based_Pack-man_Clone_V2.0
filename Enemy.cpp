//
// Created by levymaty on 18.12.20.
//
#include <random>
#include <chrono>
#include "Enemy.h"

Enemy::Enemy(Coordinates coords, Player* player) : Tile(coords) {
    this->displayChars = "SS";
    this->player = player;
}

int Enemy::getColorCode() const {
    return this->colorCode;
}

Coordinates Enemy::move(Player player, Map map) {

    switch (rand()%2) {
        case 0:
            switch (rand() % 2) {
                case 0:
                    return {coords.x, coords.y - 1};
                case 1:
                    return {coords.x, coords.y+1};
            }
        case 1:
            switch (rand()%2) {
                case 0:
                    return {coords.x-1, coords.y};
                case 1:
                    return {coords.x+1, coords.y};
            }
    }
    return coords;
}
