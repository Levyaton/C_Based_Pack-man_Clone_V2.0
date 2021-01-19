//
// Created by levymaty on 18.12.20.
//

#ifndef PAC___MAN_PLAYER_H
#define PAC___MAN_PLAYER_H


#include "Tile.h"

class Player: public Tile {
public:
    Player(Coordinates coords);
    void move(char movementInput, Tile* map);
private:
    void onUpdate() override;

    int print(int x, int y) override;

};


#endif //PAC___MAN_PLAYER_H
