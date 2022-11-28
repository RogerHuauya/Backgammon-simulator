//
// Created by Roger Huauya Mamani on 27/11/22.
//

#ifndef BACKGAMMON_SIMULATOR_PLAYER_H
#define BACKGAMMON_SIMULATOR_PLAYER_H
#include <string>
#include <vector>
#include "token.h"
#include <algorithm>

using namespace std;

class Player{
    string username, password;
    char token_type; // X, O
    vector<Token> tokens;
    bool is_player_up;

public:

    Player(string username, string password):
    username(username), password(password){}

    string get_username(){
        return username;
    }

    char getToken(){
        return token_type;
    }

    void set_token_type(char _token_type){
        token_type = _token_type;
    }

    bool get_is_player_up(){
        return is_player_up;
    }

    bool login(string pass){
        // ver si coincide el password
        if(pass== password){
            return true;
        }
        else return false;
    }

    bool move_player_token(int pos, int value);



    void init_token(bool ascendent);

    void init_token_up();

    void init_token_down();

    int find_token(int pos);

    friend class Board;
};

#endif //BACKGAMMON_SIMULATOR_PLAYER_H
