//
// Created by roger on 11/27/2022.
//

#ifndef BACKGAMMON_SIMULATOR_DICE_H
#define BACKGAMMON_SIMULATOR_DICE_H
#include <time.h>
#include <random>
using namespace std;
class Dice{
    int value;
public:
    Dice(){
        srand(time(nullptr));
    }
    void roll_dice(){
        value = rand()%6 + 1;
    }

    int roll_dice_and_get_value(){
        roll_dice();
        return value;
    }
};
#endif //BACKGAMMON_SIMULATOR_DICE_H
