//
// Created by levymaty on 18.12.20.
//

#include "Player.h"

Player::Player(Coordinates coords) : Tile(coords) {
    this->displayChars = "EE";
    this->mapChar = 'E';
    this->type = PLAYER;
}



void Player::onUpdate() {
    Tile::onUpdate();
}

void Player::print() {
    Tile::print();
}

void Player::move(char movementInput) {
    switch (movementInput)
    {

    }
}


