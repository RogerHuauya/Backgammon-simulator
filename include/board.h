//
// Created by Roger Huauya Mamani on 27/11/22.
//

#ifndef PROJECT_LAB_BOARD_H
#define PROJECT_LAB_BOARD_H
#include <vector>
#include "player.h"
#include "token.h"
using namespace std;
class Board{
    Player *player1, *player2;
public:
    void display_board(){

    }

    void set_player1(Player* player){
        player1 = player;
    }

    void set_player2(Player* player){
        player2 = player;
    }
};
#endif //PROJECT_LAB_BOARD_H
