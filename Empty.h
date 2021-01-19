//
// Created by levyaton on 1/19/21.
//

#ifndef PAC___MAN_EMPTY_H
#define PAC___MAN_EMPTY_H


#include "Tile.h"

class Empty : public Tile{


public:
    Empty(const Coordinates &coords, bool hasPoint);
    bool removePoint();
    void resetDisplayChars();

    void setHasPoint(bool value);
};


#endif //PAC___MAN_EMPTY_H
