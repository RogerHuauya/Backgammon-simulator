//
// Created by roger on 11/27/2022.
//

//
// Created by Roger Huauya Mamani on 27/11/22.
//

#include "../include/board.h"
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


void Board::reset_board() {
    for(int i = 0; i < COLUMNS_SIZE; i++){
        table[i] = "     ";
    }
}

void Board::update_table() {
    for(auto& token: player1->tokens){
        if(token.get_activate()) {
            table[token.get_position()][token.get_level()] = player1->token_type;
        }
    }

    for(auto& token: player2->tokens){
        if(token.get_activate()) {
            table[token.get_position()][token.get_level()] = player2->token_type;
        }
    }

}


void Board::display_board(){
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


}

void Board::play(){
    dice1.roll_dice();
    dice2.roll_dice();
    if(player_turn == 1){
        cout<<"−−−−−Turno de Jugador \""<< player1->get_username() << "\"-----"<<endl;
        get_choice();
        player1->move_token()
    }
    else if(player_turn == 2){
        cout<<"−−−−−Turno de Jugador \""<< player2->get_username() << "\"-----"<<endl;
    }
}

void Board::get_choice(){
    cout<<"Dados: " << dice1<<" "<<dice2<<endl;

}






