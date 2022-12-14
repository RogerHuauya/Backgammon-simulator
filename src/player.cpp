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
    tokens.push_back(new TokenUp(18,0,x));
    tokens.push_back(new TokenUp(18,1,x));
    tokens.push_back(new TokenUp(18,2,x));
    tokens.push_back(new TokenUp(18,3,x));
    tokens.push_back(new TokenUp(18,4,x));

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


bool comp_asc(Token* a, Token* b){
    if (a->position == b->position) {
        return a->level > b->level;
    }
    return a->position < b->position;
}

bool comp_desc(Token* a, Token* b){
    if (a->position == b->position) {
        return a->level > b->level;
    }
    return a->position > b->position;
}

bool Player::move_player_token(int pos, int value) {
    int index = find_token(pos);
    if(index < 0) {
        cout<< "There is no token in the position selected"<<endl;
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
    if(dest_index>=0) {
        if (tokens[dest_index]->get_level() == STACK_MAX_LENGTH - 1) {
            cout << "Can't place token on it, it is full" << endl;

            return false;
        }
    }
    if(dest_index == -1){
        tokens[index]->set_position(dest_pos);
        tokens[index]->set_level(0);
    }
    else {
        tokens[index]->set_position(dest_pos);
        tokens[index]->set_level(tokens[dest_index]->get_level() + 1);
    }
    if(is_player_up)
        sort(tokens.begin(), tokens.end(), comp_asc);
    else
        sort(tokens.begin(), tokens.end(), comp_desc);

    return true;
}


int Player::find_token(int pos){
    if(is_player_up)
        sort(tokens.begin(), tokens.end(), comp_asc);
    else
        sort(tokens.begin(), tokens.end(), comp_desc);

    for(int i = 0; i < tokens.size(); i++){
        if(pos == tokens[i]->get_position()){
            return i;
        }
    }
    return -1;
}

int Player::find_token_with_step(int pos, int step){
    if(is_player_up) {
        sort(tokens.begin(), tokens.end(), comp_asc);
        pos -= step;
    }
    else {
        sort(tokens.begin(), tokens.end(), comp_desc);
        pos += step;
    }
    for(int i = 0; i < tokens.size(); i++){
        if(pos == tokens[i]->get_position()){
            return i;
        }
    }
    return -1;
}

int Player::get_token_level_with_step(int pos, int step){
    if(is_player_up) {
        pos -= step;
    }
    else {
        pos += step;
    }
    int idx = find_token(pos);
    return tokens[idx]->get_level();
}

void Player::capture_token(int pos, int step){
    int reset_pos;
    if(is_player_up) {
        reset_pos = 0;
        pos -= step;
    }
    else{
        pos += step;
        reset_pos = COLUMNS_SIZE - 1;
    }
    pos = find_token(pos);

    int idx = find_token(0);
    if(idx < 0) {
        tokens[pos]->set_position(reset_pos);
        tokens[pos]->set_level(0);
    }
    else{
        tokens[pos]->set_position(reset_pos);
        tokens[pos]->set_level(tokens[idx]->get_level() + 1);
    }

}

Player::~Player(){
    for(auto& x:tokens){
        delete x;
    }
}

