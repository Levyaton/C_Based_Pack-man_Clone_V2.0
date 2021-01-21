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

void Player::print() {
    return Tile::print();
}



