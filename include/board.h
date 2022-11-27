//
// Created by Roger Huauya Mamani on 27/11/22.
//

#ifndef BACKGAMMON_SIMULATOR_BOARD_H
#define BACKGAMMON_SIMULATOR_BOARD_H
#include <vector>
#include "player.h"
#include "token.h"
#include "dice.h"
#include "constants.h"
#include <iostream>
#include <windows.h>
#define color SetConsoleTextAttribute
using namespace std;
class Board{
    Player *player1, *player2;
    Dice dice1, dice2;
    vector<string> table;
    int player_turn = 0;
public:
    Board(){
        dice1 = Dice();
        dice2 = Dice();
    }

    void reset_board();

    void update_table();

    void display_board();

    void set_player1(Player* player){
        player1 = player;
    }

    void set_player2(Player* player){
        player2 = player;
    }
    void play();

    void get_choice();

    friend class Player;
};
#endif //BACKGAMMON_SIMULATOR_BOARD_H
