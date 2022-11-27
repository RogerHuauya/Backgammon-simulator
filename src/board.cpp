//
// Created by roger on 11/27/2022.
//

//
// Created by Roger Huauya Mamani on 27/11/22.
//

#include "../include/board.h"
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


void Board::init_board() {
    for(int i = 0; i < COLUMNS_SIZE; i++){
        table[i] = "     ";
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





