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

    const int get_value(){
        return value;
    }

    friend ostream& operator<<(ostream &os, const Dice& d);
};

//extern ostream& operator<<(ostream &os, const Dice& d);
#endif //BACKGAMMON_SIMULATOR_DICE_H
