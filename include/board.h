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
    int player_turn = 1; // a quien le toca
public:
    Board(){
        for(int i = 0; i < COLUMNS_SIZE; i++){
            table.emplace_back("     ");
        }
        // Composition
        dice1 = Dice();
        dice2 = Dice();
    }

    void roll_dices();

    void reset_board();

    void update_table();

    void display_board();

    void init_players();

    void set_player1(Player* player){
        player1 = player;
    }

    void set_player2(Player* player){
        player2 = player;
    }

    Player* get_player1(){
        return player1;
    }

    Player* get_player2(){
        return player2;
    }

    bool play(ostream& os, istream& in);

    void play_choices(istream& in);

    friend class Player;

    int get_dice1_value();

    int get_dice2_value();
};
#endif //BACKGAMMON_SIMULATOR_BOARD_H
