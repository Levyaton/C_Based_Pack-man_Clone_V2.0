//
// Created by levymaty on 18.12.20.
//

#include <stdint.h>
#include <vector>
#include "AggressiveEnemy.h"
#include "Tile.h"

AggressiveEnemy::AggressiveEnemy(Coordinates coords, Player *player) : Enemy(coords, player) {
    this->colorCode = 31;
    this->type = AGRESSIVEENEMY;
}


Coordinates AggressiveEnemy::move(Player player, Map map) {
    Pipe *found = nullptr;
    Pipe start = Pipe(nullptr,&player);
    Channel* sewage;
    Channel* oldPipes;
    Channel* newPipes;
    while(found== nullptr){
        for(Pipe p: oldPipes->getPipes()){
            Coordinates current = p.tile->getCoords();
            Tile up = map.getTile(Coordinates(current.x, current.y-1));
            Tile down = map.getTile(Coordinates(current.x, current.y+1));
            Tile left = map.getTile(Coordinates(current.x-1, current.y));
            Tile right = map.getTile(Coordinates(current.x+1, current.y));
            if(pipeValidityAndIsPlayerCheck(&up,&p,sewage,newPipes) || pipeValidityAndIsPlayerCheck(&down,&p,sewage,newPipes) || pipeValidityAndIsPlayerCheck(&left,&p,sewage,newPipes) || pipeValidityAndIsPlayerCheck(&right,&p,sewage,newPipes)){
                found = &p;
            }
        }
        oldPipes = newPipes;
        newPipes = nullptr;
    }
    if(sewage->getPipes().size()==1){
        return player.getCoords();
    }
    return walkThroughChannel(*found);
}

bool AggressiveEnemy::pipeValidityAndIsPlayerCheck(Tile *current, AggressiveEnemy::Pipe *prev, AggressiveEnemy::Channel *sewage,
                                                   AggressiveEnemy::Channel *newPipes) {
    if(current->getType() == EMPTY || current->getType() == POINT){
        Pipe newPipe = Pipe(prev, current);
        if(!sewage->contains(newPipe)){
            newPipes->add(newPipe);
            sewage->add(newPipe);
        }
    }
    else if(current->getType() == PLAYER){
        return true;
    }
    return false;
}

Coordinates AggressiveEnemy::walkThroughChannel(AggressiveEnemy::Pipe endPoint) {
    Pipe current = endPoint;
    while (true){
        if(current.prev == nullptr){
            return current.tile->getCoords();
        }
    }
}


