//
// Created by Roger Huauya Mamani on 27/11/22.
//

#ifndef BACKGAMMON_SIMULATOR_TOKEN_H
#define BACKGAMMON_SIMULATOR_TOKEN_H
#include <stdio.h>
#include <iostream>
#include "constants.h"
using namespace std;

class Token {
protected:
    int position, level;
    bool activate;
    bool is_token_up;
public:
    Token(int _position, int _level) : position(_position), level(_level) {
        activate = true;
    }

    void set_position(int pos) {
        position = pos;
    }

    void set_level(int lev) {
        level = lev;
    }

    int get_position(){
        return position;
    }

    bool get_activate(){
        return true;
    }

    int get_level(){
        return level;
    }

    bool get_token_type() {
        return is_token_up;
    }

    void move_token(int hop, int _level);

    friend bool comp(Token a, Token b);
    ~Token() {};

};


/*
class TokenUp:public Token{
public:
    TokenUp(int pos, int lvl): Token(pos,lvl){
        is_token_up = true;
    }
    void move_token(int hop, int _level){
        position += hop;
        level = _level;
    }
    int get_position(){
        return position;
    }

    int get_level(){
        return level;
    }

    bool get_activate(){
        return activate;
    }

    bool operator < ( TokenUp& token) const{
        if (position == token.get_position()) {
            return level > token.get_level();
        }
        return position < token.get_position();
    }
};

class TokenDown:public Token{
public:
    TokenDown(int pos, int lvl): Token(pos,lvl){
        bool is_token_up = 1;
    }
    void move_token(int hop, int _level){
        position -= hop;
        level = _level;
    }

    int get_position(){
        return position;
    }

    int get_level(){
        return level;
    }

    bool get_activate(){
        return activate;
    }

    bool operator < (const TokenDown& token) const{
        if (position == token.position) {
            return level > token.level;
        }
        return position < token.position;
    }
};
 */
#endif //BACKGAMMON_SIMULATOR_TOKEN_H
