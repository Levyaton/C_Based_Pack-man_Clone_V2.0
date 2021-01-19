//
// Created by levymaty on 18.12.20.
//

#include "Player.h"

Player::Player(Coordinates coords) : Tile(coords) {
    this->displayChars = "EE";
    this->type = PLAYER;
}



void Player::onUpdate() {
    Tile::onUpdate();
}

int Player::print(int x, int y) {
    return Tile::print(x, y);
}



