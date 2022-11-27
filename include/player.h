//
// Created by Roger Huauya Mamani on 27/11/22.
//

#ifndef BACKGAMMON_SIMULATOR_PLAYER_H
#define BACKGAMMON_SIMULATOR_PLAYER_H
#include <string>
#include <vector>
#include "token.h"

using namespace std;

class Player{
    string username, password;
    char token_type; // X, O
    vector<Token> tokens;
    bool is_bottom;
public:
    Player(string username, string password, bool _is_bottom):
    username(username), password(password), is_bottom(_is_bottom){

    }
    void set_token_type(char _token_type){
        token_type = _token_type;
    }
};

#endif //BACKGAMMON_SIMULATOR_PLAYER_H
