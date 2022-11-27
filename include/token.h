//
// Created by Roger Huauya Mamani on 27/11/22.
//

#ifndef BACKGAMMON_SIMULATOR_TOKEN_H
#define BACKGAMMON_SIMULATOR_TOKEN_H
#include <stdio.h>
#include <iostream>
#include "constants.h"
using namespace std;

class Token{
    int position, level;
public:
    Token(int _position, int _level):position(_position),level(_level){}
    void move_token(int hop, int _level){

    }

};
#endif //BACKGAMMON_SIMULATOR_TOKEN_H
