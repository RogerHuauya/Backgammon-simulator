

#include "../include/board.h"
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


void Board::reset_board() {
    for(auto & i : table){
        i = "     ";
    }
}


void Board::update_table() {
    for(auto& token: player1->tokens){

        if(token->get_position() > -1 && token->get_position() < COLUMNS_SIZE) {
            table[token->get_position()][token->get_level()] = player1->token_type[0];
        }
    }

    for(auto& token: player2->tokens){

        if(token->get_position() > -1 && token->get_position() < COLUMNS_SIZE) {
            table[token->get_position()][token->get_level()] = player2->token_type[0];
        }
    }

}


void Board::roll_dices(){
    dice1.roll_dice();
    dice2.roll_dice();
}


void Board::display_board(){
    color(hConsole,12);
    cout << "\t\t\tFichas X\tLiberadas: 0\tCapturadas: 0\n";
    //Impresion de los números
    color(hConsole,14);
    std::cout << DIVISION_LINE << "\n";
    std::cout << "|";
    for(int i = 13; i<=24; i++){
        if(i==19){
            color(hConsole,14);
            cout << "| | \t";
        }
        else if(i==24){
            color(hConsole,10);
            cout << i;
            continue;
        }
        color(hConsole,10);
        cout << i << "\t";
    }
    color(hConsole,14);
    cout << "|";
    cout << endl;


    //Impresion de las fichas superiores

    for(int i=0; i<STACK_MAX_LENGTH;i++){
        color(hConsole,14);
        cout << "|";
        for(int j=12; j<COLUMNS_SIZE;j++){
            if(j==18){
                color(hConsole,14);
                cout << "| | \t";
            }
            else if(j==23) {
                if(table[j][i] == 'X') {
                    color(hConsole,12);
                    cout << table[j][i];
                    continue;
                }else if(table[j][i] == 'O'){
                    color(hConsole,11);
                    cout << table[j][i];
                    continue;
                }else{
                    cout << table[j][i];
                    continue;
                }
            }
            if(table[j][i] == 'X') {
                color(hConsole,12);
                cout << table[j][i] << "\t" ;
            }else if(table[j][i] == 'O'){
                color(hConsole,11);
                cout << table[j][i] << "\t" ;
            }else{
                cout << table[j][i] << "\t" ;
            }

        }
        color(hConsole,14);
        cout << " |";
        cout << endl;
    }
    cout << DIVISION_LINE <<"\n";


    //Impresion de las fichas inferiores

    for(int i=0; i<STACK_MAX_LENGTH;i++){
        color(hConsole,14);
        cout << "|";
        for(int j=11; j>=0;j--){
            if(j==5){
                color(hConsole,14);
                cout << "| | \t";
            }
            else if(j==0) {
                if(table[j][4-i] == 'X'){
                    color(hConsole,12);
                    cout << table[j][4-i];
                    continue;
                }else if(table[j][4-i] == 'O'){
                    color(hConsole,11);
                    cout << table[j][4-i];
                    continue;
                }else{
                    cout << table[j][4-i];
                    continue;
                }

            }
            if(table[j][4-i] == 'X'){
                color(hConsole,12);
                cout << table[j][4-i] << "\t" ;
            }else if(table[j][4-i] == 'O'){
                color(hConsole,11);
                cout << table[j][4-i] << "\t" ;
            }else{
                cout << table[j][4-i] << "\t" ;
            }

        }
        color(hConsole,14);
        cout << " |";
        cout << endl;
    }
    cout << "|";
    for(int i = 12; i>=1; i--){
        if(i==6){
            color(hConsole,14);
            cout << "| | \t";
        }
        else if(i==1){
            color(hConsole,10);
            cout << i;
            continue;
        }
        color(hConsole,10);
        cout << i << "\t";
    }
    color(hConsole,14);
    cout << " |";
    cout << endl;
    cout << DIVISION_LINE <<"\n";
    color(hConsole,11);
    cout << "\t\t\tFichas O\tLiberadas: 0\tCapturadas: 0\n";
    color(hConsole,7);

}


bool Board::play(ostream &os, istream &in){
    this->roll_dices();

    if(player_turn == 1){
        os<<"----- Turno de Jugador 1: \""<< player1->get_username() << "\" ("<<player1->get_token_type() << ") -----"<<endl;
        play_choices(in);
        player_turn = 2;
    }
    else if(player_turn == 2){
        os<<"----- Turno de Jugador 2: \""<< player2->get_username() << "\" ("<<player2->get_token_type() << ") -----"<<endl;
        play_choices(in);
        player_turn = 1;
    }
    return false;
}


void Board::play_choices(istream& in){
    cout<<"Dados: " << dice1 <<", "<< dice2<<endl;
    int turns, pos;
    if(dice1.get_value() == dice2.get_value()) turns = 2;
    else turns = 1;

    for(int i = 0; i < turns; i++) {
        if (player_turn == 1) {
            bool result = false;
            while (!result) {
                cout << "Posicion de ficha a mover " << dice1 << " posiciones [1-24]: ";
                in >> pos;
                pos--;
                if(player2->find_token_with_step(pos, dice1.get_value()) != -1) {
                    if(player2->get_token_level_with_step(pos, dice1.get_value()) > 0) {
                        cout << "Jugada invalida, hay mas de una ficha enemiga en el destino, intente nuevamente"
                             << endl;
                        continue;
                    }
                    else{
                        cout << "Hay una ficha enemiga, capturando ... "<<endl;
                        player2->capture_token(pos, dice1.get_value());
                    }
                }
                result = player1->move_player_token(pos, dice1.get_value());
                if(!result){
                    cout<< "Jugada invalida, intente nuevamente"<<endl;
                }
            }
            result = false;
            while (!result) {
                cout << "Posicion de ficha a mover " << dice2 << " posiciones [1-24]: ";
                in >> pos;
                pos--;
                if(player2->find_token_with_step(pos, dice2.get_value()) != -1) {
                    if(player2->get_token_level_with_step(pos, dice2.get_value()) > 0) {
                        cout << "Jugada invalida, hay mas de una ficha enemiga en el destino, intente nuevamente"
                             << endl;
                        continue;
                    }
                    else{
                        cout << "Hay una ficha enemiga, capturando ... "<<endl;
                        player2->capture_token(pos, dice2.get_value());
                    }
                }
                result = player1->move_player_token(pos, dice2.get_value());
                if(!result){
                    cout<< "Jugada invalida, intente nuevamente"<<endl;
                }
            }

        } else {
            bool result = false;
            while (!result) {
                cout << "Posicion de ficha a mover " << dice1 << " posiciones [1-24]: ";
                in >> pos;
                pos--;
                if(player1->find_token_with_step(pos, dice1.get_value()) != -1) {
                    if(player1->get_token_level_with_step(pos, dice1.get_value()) > 0) {
                        cout << "Jugada invalida, hay mas de una ficha enemiga en el destino, intente nuevamente"
                             << endl;
                        continue;
                    }
                    else{
                        cout << "Hay una ficha enemiga, capturando ... "<<endl;
                        player1->capture_token(pos, dice1.get_value());
                    }
                }
                result = player2->move_player_token(pos, dice1.get_value());
                if(!result){
                    cout<< "Jugada invalida, intente nuevamente"<<endl;
                }
            }
            result = false;
            while (!result) {
                cout << "Posicion de ficha a mover " << dice2 << " posiciones [1-24]: ";
                in >> pos;
                pos--;
                if(player1->find_token_with_step(pos, dice2.get_value()) != -1) {
                    if(player1->get_token_level_with_step(pos, dice2.get_value()) > 0) {
                        cout << "Jugada invalida, hay mas de una ficha enemiga en el destino, intente nuevamente"
                             << endl;
                        continue;
                    }
                    else{
                        cout << "Hay una ficha enemiga, capturando ... "<<endl;
                        player1->capture_token(pos, dice2.get_value());
                    }
                }
                result = player2->move_player_token(pos, dice2.get_value());
                if(!result){
                    cout<< "Jugada invalida, intente nuevamente"<<endl;
                }
            }
        }
    }
}


int Board::get_dice1_value(){
    return dice1.get_value();
}


int Board::get_dice2_value(){
    return dice2.get_value();
}




