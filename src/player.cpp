//
// Created by roger on 11/27/2022.
//

#include "../include/player.h"
#include "../include/token.h"

void Player::init_token_up(){

    tokens.push_back(Token(0,0));
    tokens.push_back(Token(0,1));
    tokens.push_back(Token(11,0));
    tokens.push_back(Token(11,1));
    tokens.push_back(Token(11,2));
    tokens.push_back(Token(11,3));
    tokens.push_back(Token(11,4));
    tokens.push_back(Token(16,0));
    tokens.push_back(Token(16,1));
    tokens.push_back(Token(16,2));
    tokens.push_back(Token(19,0));
    tokens.push_back(Token(19,1));
    tokens.push_back(Token(19,2));
    tokens.push_back(Token(19,3));
    tokens.push_back(Token(19,4));

}


void Player:: init_token_down(){
    tokens.push_back(Token(23,0));
    tokens.push_back(Token(23,1));
    tokens.push_back(Token(12,0));
    tokens.push_back(Token(12,1));
    tokens.push_back(Token(12,2));
    tokens.push_back(Token(12,3));
    tokens.push_back(Token(12,4));
    tokens.push_back(Token(7,0));
    tokens.push_back(Token(7,1));
    tokens.push_back(Token(7,2));
    tokens.push_back(Token(5,0));
    tokens.push_back(Token(5,1));
    tokens.push_back(Token(5,2));
    tokens.push_back(Token(5,3));
    tokens.push_back(Token(5,4));

}

void Player::init_token(bool ascendent) {
    is_player_up = ascendent;
    if (is_player_up){
        init_token_up();
    }else{
        init_token_down();
    }
}

bool comp(Token a, Token b){
    if (a.position == b.position) {
        return a.level > b.level;
    }
    return a.position < b.position;
}

bool Player::move_player_token(int pos, int value) {
    int index = find_token(pos);
    if(index < 0) {
        cout<< "There is no token in the position selected"<<endl;
        return false;
    }
    int dest_pos;
    if(is_player_up) {
        dest_pos = tokens[index].get_position() + value;
    }
    else{
        dest_pos = tokens[index].get_position() - value;
    }
    int dest_index = find_token(dest_pos);
    if (tokens[dest_index].get_level() == STACK_MAX_LENGTH - 1){
        cout<< "Can't place token on it, full";
        return false;
    }
    if(dest_index == -1){
        tokens[index].set_position(dest_pos);
        tokens[index].set_level(0);
    }
    else {
        tokens[index].set_position(dest_pos);
        tokens[index].set_level(tokens[dest_index].get_level() + 1);
    }
    sort(tokens.begin(), tokens.end(), comp);

    return true;
}


int Player::find_token(int pos){
    sort(tokens.begin(), tokens.end(), comp);
    for(int i = 0; i < tokens.size(); i++){
        if(pos == tokens[i].get_position()){
            return i;
        }
    }
    return -1;
}



