//
// Created by levymaty on 18.12.20.
//
#include <cstdint>
#include <string>
#include "algorithm"
#include <string>
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
    EMPTY,
    ENEMY,
    PLAYER,
    WALL
};
class Tile {

protected:
    TileType type;
    char mapChar;
    std::string displayChars;
    Coordinates coords;
    bool containsPoint;
public:


    Tile(const Coordinates &coords);

    virtual void onUpdate();
    virtual void print();

    char getMapChar() const;

    const std::string &getDisplayChars() const;

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
