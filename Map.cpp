//
// Created by levymaty on 18.12.20.
//

#include "Map.h"
#include "Wall.h"
#include "Empty.h"
#include <fstream>
#include <vector>
#include <Enemies/AggressiveEnemy.h>
#include <Enemies/ScaredEnemy.h>
#include <Enemies/RandomEnemy.h>

Map::Map(Tile **tiles, int width, int height) {
    this->tiles = tiles;
    this->height = height;
    this->width = width;
    player = nullptr;
    enemies = nullptr;
}

Tile Map::getTile(Coordinates coords) {
    return tiles[coords.y][coords.x];
}

void Map::swapTile(Coordinates dest, const Tile& sourceTile) {
    Tile &chosen = tiles[dest.y][dest.x];
    bool chosenHasPoint = chosen.hasPoint();
    bool sourceHasPoint = sourceTile.hasPoint();

    tiles[sourceTile.getCoords().y][sourceTile.getCoords().x] = chosen;


    tiles[dest.y][dest.x] = sourceTile;
}

int Map::getWidth() const {
    return this->width;
}

int Map::getHeight() const {
    return this->height;
}

Map::Map(std::string path) {
    std::ifstream inputFile(path);
    std::string line;
    Enemy * temp;
    std::vector<std::string> lines;
    while (std::getline(inputFile, line)) {
        lines.push_back(line);
    }
    this->width = lines.at(0).length();
    this->height = lines.size();
    Tile * tempTiles[width*height];
    tiles = tempTiles;
    for(int y = 0; y < this->height; y++){
        if(lines.at(y).length() != this->width){
            throw std::runtime_error("Inconsistant maze width");
        }
        for (int x = 0; x < this->width; x++){
            switch (line.at(x)) {
                case AGRESSIVEENEMY:
                    temp = new AggressiveEnemy(Coordinates(x,height), player);
                    enemies.push_back(temp);
                    tiles[width * y + x] = temp;
                    break;
                case SCAREDENEMY:
                    temp = new ScaredEnemy(Coordinates(x,height), player);
                    enemies.push_back(temp);
                    tiles[width * y + x] = temp;
                    break;
                case RANDOMENEMY:
                    temp = new RandomEnemy(Coordinates(x,height));
                    enemies.push_back(temp);
                    tiles[width * y + x] = temp;
                    break;
                case WALL:
                    tiles[width * y + x] = new Wall(Coordinates(x,height));
                    break;
                case POINT:
                    tiles[width * y + x] = new Empty(Coordinates(x,height), true);
                    break;
                case EMPTY:
                    tiles[width * y + x] = new Empty(Coordinates(x,height), false);
                    break;
                case PLAYER:
                    if(player== nullptr){
                        this->player = new Player({x,y});
                        tiles[width * y + x] = this->player;
                        break;
                    }
                    else{
                        throw std::runtime_error("Multiple Players are unsupported");
                    }
                default:
                    std::string msg = &"Unknown tile symbol: " [ (char)line.at(x)];
                    throw std::runtime_error(msg);
            }
        }
    }

}
