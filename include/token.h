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
    bool activate = true;
    bool ascendent;
    string token_type;
public:
    Token(int _position, int _level, string token_type) : position(_position), level(_level),token_type(token_type) {}

    void set_position(int pos) {
        position = pos;
    }

    void set_level(int lev) {
        level = lev;
    }

    virtual int get_position() = 0;

    virtual bool get_activate()=0;

    virtual int get_level()=0;

    virtual string get_token_type() =0;

    virtual void move_token(int hop, int _level) = 0;

    friend bool comp_asc(Token* a, Token* b);

    friend bool comp_desc(Token* a, Token* b);

    ~Token() {}

};



class TokenUp:public Token{
public:
    TokenUp(int pos, int lvl, string token): Token(pos,lvl,token){
        ascendent = true;
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

    string get_token_type(){
        return token_type;
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
    TokenDown(int pos, int lvl,string token): Token(pos,lvl,token){
        ascendent = false;
    }

    void move_token(int hop, int _level){
        position -= hop;
        level = _level;
    }

    int get_position(){
        return position;
    }

    string get_token_type(){
        return token_type;
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

#endif //BACKGAMMON_SIMULATOR_TOKEN_H
