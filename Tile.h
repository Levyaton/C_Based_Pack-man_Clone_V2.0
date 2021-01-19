//
// Created by levymaty on 18.12.20.
//
#include <cstdint>
#include <string>
#include "algorithm"
#include <string>
#include <curses.h>

#ifndef PAC_MAN_TILE_H
#define PAC_MAN_TILE_H


struct Coordinates{
public:
    int x;
    int y;
   Coordinates(int x, int y);

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

};

enum TileType{
    EMPTY = ' ',
    POINT = 'P',
    AGRESSIVEENEMY = 'A',
    SCAREDENEMY = 'S',
    RANDOMENEMY = 'R',
    PLAYER = 'E',
    WALL = 'X'
};
class Tile {

protected:
    TileType type;

    std::string displayChars;
    Coordinates coords;
    bool containsPoint;
public:


    Tile(const Coordinates &coords);

    virtual void onUpdate();
    virtual int print(int x, int y);



    static void setMapChar(char mapChar);

    std::string &getDisplayChars();

    void setCoords(const Coordinates &coords);

    bool isContainsPoint() const;

    void setContainsPoint(bool containsPoint);


    bool hasPoint() const;

    void setHasPoint(bool value){
        this->containsPoint = value;
    }

    const Coordinates &getCoords() const;

    TileType getType() const;
};


#endif //PAC_MAN_TILE_H
