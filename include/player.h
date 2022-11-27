//
// Created by Roger Huauya Mamani on 27/11/22.
//

#ifndef PROJECT_LAB_PLAYER_H
#define PROJECT_LAB_PLAYER_H
#include <string>
#include <vector>
#include "token.h"

using namespace std;

class Player{
    string username, password;
    char token_type; // X, O
    vector<Token> tokens;
public:
    Player(string username, string password):username(username), password(password) {

    }
    void set_token_type(char ){

    }
};

#endif //PROJECT_LAB_PLAYER_H
