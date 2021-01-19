//
// Created by levymaty on 18.12.20.
//

#ifndef PAC_MAN_MAIN_H
#define PAC_MAN_MAIN_H

using namespace std;
#include <chrono>
#include <ncurses.h>
#include <curses.h>
#include <thread>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include<cstdio>
#include <csignal>
#include <vector>
#include <fstream>
#include <iostream>
#include <chrono>
#include "Tile.h"
#include "Player.h"
#include "Enemy.h"
#include "Enemies/AggressiveEnemy.h"
#include "Enemies/RandomEnemy.h"
#include "Enemies/ScaredEnemy.h"
#include "Wall.h"
#include "Empty.h"

 void parseLine(int width,int height,string line, Player* player,  vector<Enemy*>& enemies,  vector<Tile*>& target){

    for(int x = 0; x < width;x++){
        Tile* current = nullptr;
        Enemy* enemy = nullptr;
        switch (line.at(x)) {
            case AGRESSIVEENEMY:
               enemy = new AggressiveEnemy(Coordinates(x,height), player);
               enemies.push_back(enemy);
               current = enemy;
               break;
            case SCAREDENEMY:
                enemy = new ScaredEnemy(Coordinates(x,height), player);
                enemies.push_back(enemy);
                current = enemy;
                break;
            case RANDOMENEMY:
                enemy = new RandomEnemy(Coordinates(x,height));
                enemies.push_back(enemy);
                current = enemy;
                break;
            case WALL:
                current = new Wall(Coordinates(x,height));
                break;
            case POINT:
                current = new Empty(Coordinates(x,height), true);
                break;
            case EMPTY:
                current = new Empty(Coordinates(x,height), false);
                break;
            case PLAYER:
                if(player->getCoords().x == -666){
                    player->setCoords({x,height});
                    current = player;
                    break;
                }
                throw runtime_error("Multiple Players are unsupported");
            default:
                string msg = "Unknown tile symbol: " + (char)line.at(x);
                throw runtime_error(msg);
        }
       target.push_back(current);
    }
}

void parseMapFile(const string& path,int &height, int &width, Player player,  vector<Enemy*>& enemies,  vector<Tile*>& target){
    ifstream inputFile(path);
    string line;
    if(std::getline(inputFile, line)){
        width = line.length();
        height = 1;
        parseLine(width,height-1, line, &player, enemies,target);
        while (std::getline(inputFile, line)) {
            if(line.length()!= width){
                throw runtime_error("Inconsistant maze width");
            }
            height += 1;
            parseLine(width,height-1, line, &player, enemies,target);
        }
   //     cout<<"Map parsing successful!";
    }
    else{
        cout<<line<<endl;
        throw runtime_error("Empty Map!");
    }


}


int main(){
    string path = "../Map.txt";
    int height;
    int width;
    initscr();
    auto* player = new Player({-666,-666});
    vector<Enemy*> enemies;
    int score = 0;

    vector<Tile*> protoTiles;
    parseMapFile(path,height,width, *player, enemies, protoTiles);
    Tile** tiles = &protoTiles[0];
    clear();
    refresh();

    curs_set(0);
    while (true){
        int counter;
        for(int y = 0;y < width; y++){
            counter = 0;
            for(int x = 0; x < height; x++){
                counter += tiles[width * x + y]->print(y,x+counter);
            }
        }
        refresh();


     //   std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
    



}




#endif //PAC_MAN_MAIN_H
