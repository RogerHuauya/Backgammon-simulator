//
// Created by Roger Huauya Mamani on 27/11/22.
//

#ifndef BACKGAMMON_SIMULATOR_MENU_H
#define BACKGAMMON_SIMULATOR_MENU_H
#include <string>
#include <iostream>
#include "player.h"
#include "board.h"
void menu();
void register_player();
void set_turn();
void init_game();
bool validate_number_of_players();
void clear_terminal();
#endif //BACKGAMMON_SIMULATOR_MENU_H
