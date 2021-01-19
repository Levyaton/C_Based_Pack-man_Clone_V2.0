//
// Created by levyaton on 1/19/21.
//

#include "Empty.h"

Empty::Empty(const Coordinates &coords,bool hasPoint) : Tile(coords) {
   resetDisplayChars();
}

void Empty::resetDisplayChars(){
    if(hasPoint()){
        this->type = POINT;
        this->displayChars = " 0";
    }
    else{
        this->type = EMPTY;
        this->displayChars = "  ";
    }
}


bool Empty::removePoint() {
   if(this->hasPoint()){
       this->setHasPoint(false);
       this->type = EMPTY;
       this->displayChars = "  ";
       return true;
   }
   return false;
}

void Empty::setHasPoint(bool value) {
    Tile::setHasPoint(value);
    resetDisplayChars();
}





