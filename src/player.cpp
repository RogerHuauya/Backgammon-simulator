//
// Created by roger on 11/27/2022.
//

#include "../include/player.h"
#include "../include/token.h"

void Player::init_token_up(string x){

    tokens.push_back(new TokenUp(0,0,x));
    tokens.push_back(new TokenUp(0,1,x));
    tokens.push_back(new TokenUp(11,0,x));
    tokens.push_back(new TokenUp(11,1,x));
    tokens.push_back(new TokenUp(11,2,x));
    tokens.push_back(new TokenUp(11,3,x));
    tokens.push_back(new TokenUp(11,4,x));
    tokens.push_back(new TokenUp(16,0,x));
    tokens.push_back(new TokenUp(16,1,x));
    tokens.push_back(new TokenUp(16,2,x));
    tokens.push_back(new TokenUp(19,0,x));
    tokens.push_back(new TokenUp(19,1,x));
    tokens.push_back(new TokenUp(19,2,x));
    tokens.push_back(new TokenUp(19,3,x));
    tokens.push_back(new TokenUp(19,4,x));

}


void Player:: init_token_down(string x){
    tokens.push_back(new TokenDown(23,0,x));
    tokens.push_back(new TokenDown(23,1,x));
    tokens.push_back(new TokenDown(12,0,x));
    tokens.push_back(new TokenDown(12,1,x));
    tokens.push_back(new TokenDown(12,2,x));
    tokens.push_back(new TokenDown(12,3,x));
    tokens.push_back(new TokenDown(12,4,x));
    tokens.push_back(new TokenDown(7,0,x));
    tokens.push_back(new TokenDown(7,1,x));
    tokens.push_back(new TokenDown(7,2,x));
    tokens.push_back(new TokenDown(5,0,x));
    tokens.push_back(new TokenDown(5,1,x));
    tokens.push_back(new TokenDown(5,2,x));
    tokens.push_back(new TokenDown(5,3,x));
    tokens.push_back(new TokenDown(5,4,x));

}

void Player::init_token(bool ascendent) {
    is_player_up = ascendent;
    if (is_player_up){
        init_token_up(token_type);
    }else{
        init_token_down(token_type);
    }
}

bool comp(Token* a, Token* b){
    if (a->position == b->position) {
        return a->level > b->level;
    }
    return a->position < b->position;
}

bool Player::move_player_token(int pos, int value) {
    int index = find_token(pos);
    if(index < 0) {
        cout<< "index not valid";
        return false;
    }
    int dest_pos;
    if(is_player_up) {
        dest_pos = tokens[index]->get_position() + value;
    }
    else{
        dest_pos = tokens[index]->get_position() - value;
    }
    int dest_index = find_token(dest_pos);
    if (tokens[dest_index]->get_level() == STACK_MAX_LENGTH){
        cout<< "Can't place token on it";
        return false;
    }
    if(dest_index == -1){
        tokens[index]->set_position(dest_pos);
        tokens[index]->set_level(0);
    }
    else {
        tokens[index]->set_position(dest_pos);
        tokens[index]->set_level(tokens[dest_index]->get_level() + 1);
    }
    sort(tokens.begin(), tokens.end(), comp);

    return true;
}


int Player::find_token(int pos){
    sort(tokens.begin(), tokens.end(), comp);
    for(int i = 0; i < tokens.size(); i++){
        if(pos == tokens[i]->get_position()){
            return i;
        }
    }
    return -1;
}



