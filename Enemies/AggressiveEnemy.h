//
// Created by levymaty on 18.12.20.
//

#ifndef PAC___MAN_AGGRESSIVEENEMY_H
#define PAC___MAN_AGGRESSIVEENEMY_H


#include <Enemy.h>
#include <vector>

class AggressiveEnemy: public Enemy {
public:

    struct Pipe{
        Pipe* prev;
        Tile *tile;

        Pipe(Pipe* const &prev, Tile* tile){
            this->tile = tile;
            this->prev = prev;
        }
        bool visited = false;

        Pipe *getPrev() const {
            return prev;
        }

        void setPrev(Pipe *prev) {
            Pipe::prev = prev;
        }

        bool isVisited() const {
            return visited;
        }

        void setVisited(bool visited) {
            Pipe::visited = visited;
        }

        Tile *getTile() const {
            return tile;
        }

    };
    struct Channel{

    private:
        std::vector<Pipe> pipes;
    public:
        void add(Pipe pipe){
            pipes.push_back(pipe);
        }

        std::vector<Pipe>  getPipes(){
            return pipes;
        }

        bool contains(Pipe requested){
            for(Pipe p: pipes){
                Coordinates requestedCoords = requested.tile->getCoords();
                Coordinates pCoords = p.tile->getCoords();
                if(pCoords.x == requestedCoords.x && pCoords.y == requestedCoords.y ){
                    return true;
                }
            }
            return false;
        }


    };

    AggressiveEnemy(Coordinates coords, Player *player);

private:
    Coordinates walkThroughChannel(Pipe endPoint);
    Coordinates move(Player player, Map map);
    bool pipeValidityAndIsPlayerCheck(Tile* current, Pipe* prev, Channel* sewage, Channel* newPipes);

};


#endif //PAC___MAN_AGGRESSIVEENEMY_H
