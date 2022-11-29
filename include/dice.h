//
// Created by roger on 11/27/2022.
//

#ifndef BACKGAMMON_SIMULATOR_DICE_H
#define BACKGAMMON_SIMULATOR_DICE_H
#include <time.h>
#include <random>
#include <iostream>
using namespace std;
class Dice{
    int value;
public:
    Dice(){
        srand(time(nullptr));
        roll_dice();
    }

    void roll_dice();

    int get_value();

    friend ostream& operator<<(ostream &os, const Dice& d); // Overloading operator
};

#endif //BACKGAMMON_SIMULATOR_DICE_H
