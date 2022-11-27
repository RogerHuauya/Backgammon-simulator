//
// Created by roger on 11/27/2022.
//

#include "../include/player.h"
#include "../include/token.h"

void Player::init_token_up(){

    tokens[0] = TokenUp(0,0);
    tokens[1] = TokenUp(0,1);
    tokens[2] = TokenUp(11,0);
    tokens[3] = TokenUp(11,1);
    tokens[4] = TokenUp(11,2);
    tokens[5] = TokenUp(11,3);
    tokens[6] = TokenUp(11,4);
    tokens[7] = TokenUp(16,0);
    tokens[8] = TokenUp(16,1);
    tokens[9] = TokenUp(16,2);
    tokens[10] = TokenUp(19,0);
    tokens[11] = TokenUp(19,1);
    tokens[12] = TokenUp(19,2);
    tokens[13] = TokenUp(19,3);
    tokens[14] = TokenUp(19,4);

}


void Player:: init_token_down(){

    tokens[0] = TokenDown(23,0);
    tokens[1] = TokenDown(23,1);
    tokens[2] = TokenDown(12,0);
    tokens[3] = TokenDown(12,1);
    tokens[4] = TokenDown(12,2);
    tokens[5] = TokenDown(12,3);
    tokens[6] = TokenDown(12,4);
    tokens[7] = TokenDown(7,0);
    tokens[8] = TokenDown(7,1);
    tokens[9] = TokenDown(7,2);
    tokens[10] = TokenDown(5,0);
    tokens[11] = TokenDown(5,1);
    tokens[12] = TokenDown(5,2);
    tokens[13] = TokenDown(5,3);
    tokens[14] = TokenDown(5,4);

}

void Player::init_token(bool ascendent) {
    if (ascendent){
        init_token_up();
    }else{
        init_token_down();
    }
}



bool Player::move_player_token(int pos, int value) {
    int index = find_token(pos);
    if(index < 0) return false;
    int dest_pos = tokens[index].get_position() + value;
    int dest_index = find_token(dest_pos);
    if (tokens[dest_index].get_level() == STACK_MAX_LENGTH || tokens[dest_index].get_token_type() != is_player_up)
        return false;
    tokens[index].set_position(dest_pos);
    tokens[index].set_level(tokens[dest_index].get_level() + 1);
    //sort(tokens.begin(), tokens.end(), greater<Token>());

    return true;
}


int Player::find_token(int pos){
    //sort(tokens.begin(), tokens.end(), [](Token const & a, Token const & b) -> bool
    //{ return true; });
    for(int i = 0; i < tokens.size(); i++){
        if(pos == tokens[i].get_position()){
            return i;
        }
    }
    return -1;
}



