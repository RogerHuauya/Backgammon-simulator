//
// Created by roger on 11/27/2022.
//
#include "../include/dice.h"

int Dice::get_value() {
    return value;
}

void Dice::roll_dice() {
    value = rand()%6 + 1;
}

ostream& operator<<(ostream &os, const Dice& d){
    os << d.value;
    return os;
}
