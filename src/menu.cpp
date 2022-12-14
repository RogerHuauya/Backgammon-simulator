//
// Created by roger on 11/27/2022.
//
#include "../include/menu.h"

using namespace std;

vector<Player> player_list;
Board game_board;
int op;


void register_player(){
    string name, password;
    cout<<"Ingrese su usuario: ";
    cin>>name;
    cout<<"Ingrese su contrasena: ";
    cin>>password;

    cout<<"Usuario "<<name<<" creado exitosamente"<<endl;
    player_list.emplace_back(name, password); //Player(name, password)

}

void set_turn(){ // Aqui se produce la asociacion de player 1 y player 2
    string name, pass;
    bool ans1 = false;
    bool ans2 = false;
    cout<<"Jugador 1"<<endl;
    cout<<"Ingrese su usuario: ";
    cin>>name;
    cout<<"Ingrese su contrasena: ";
    cin>>pass;
    for(auto & player : player_list){
        if(player.get_username() == name) {
            ans1 = player.login(pass);
            if (ans1) {
                game_board.set_player1(&player);
            }
        }
    }
    if(!ans1){
        cout << "¡Datos incorrectos!" << endl << "Por favor vuelva a ingresar su usuario" << endl;
        game_board.set_player1(nullptr);
        game_board.set_player2(nullptr);
        return;
    }
    name = ""; pass = "";
    cout<<"Jugador 2"<<endl;
    cout<<"Ingrese su usuario: ";
    cin>>name;
    cout<<"Ingrese su contrasena: ";
    cin>>pass;
    for(auto & player : player_list){
        if(player.get_username() == name) {
            ans2 = player.login(pass);
            if (ans2) {
                game_board.set_player2(&player);
            }
        }
    }
    if(!ans2){
        cout << "¡Datos incorrectos!" << endl << "Por favor vuelva a ingresar su usuario" << endl;
        game_board.set_player2(nullptr);
        game_board.set_player1(nullptr);
        return;
    }

    int d1,d2,d3,d4;
    string ficha1, ficha2;

    game_board.roll_dices();
    d1 = game_board.get_dice1_value();
    d2 = game_board.get_dice2_value();
    cout << "Dados para \"" << game_board.get_player1()->get_username() << "\": "<< d1 << ", " << d2 << endl;

    game_board.roll_dices();
    d3 = game_board.get_dice1_value();
    d4 = game_board.get_dice2_value();
    cout << "Dados para \"" << game_board.get_player2()->get_username() << "\": "<< d3 << ", " << d4 << endl;

    if ((d1+d2)>=(d3+d4)) {
        cout << "El jugador \"" << game_board.get_player1()->get_username() << "\" elige la ficha [X u O]: ";
        cin >> ficha1;
        if(ficha1=="X"){ficha2="O";}
        else if (ficha1 ==  "O"){ficha2 =  "X";}
    } else{
        cout << "El jugador \"" << game_board.get_player2()->get_username() << "\" elige la ficha [X u O]: ";
        cin >> ficha2;
        if(ficha2== "X"){ficha1= "O";}
        else if (ficha2 ==  "O"){ficha1 =  "X";}
    }
    game_board.get_player1()->set_token_type(ficha1[0]);
    game_board.get_player1()->init_token(ficha1[0] == 'X');

    game_board.get_player2()->set_token_type(ficha2[0]);
    game_board.get_player2()->init_token(ficha2[0] == 'X');

    cout << "Jugador \"" << game_board.get_player1()->get_username() << "\" jugara con la ficha ";
    cout << game_board.get_player1()->get_token_type()<<endl;

    cout << "Jugador \"" << game_board.get_player2()->get_username() << "\" jugara con la ficha ";
    cout << game_board.get_player2()->get_token_type()<<endl;

    system("pause");
}

void init_game(){
    clear_terminal();
    if(validate_number_of_players()){
        game_board.reset_board();
        game_board.update_table();
        bool finished = false;
        while(!finished) {
            game_board.display_board();
            finished = game_board.play(cout, cin);
            game_board.reset_board();
            game_board.update_table();
            //clear_terminal();
        }

    } else {
        cout<<"Numero de usuarios menor a 2";
    }
}


bool validate_number_of_players(){
    if(player_list.size()<2){
        return false;
    }
    else{
        return true;
    }
}


void clear_terminal(){
    system("cls");
}


void menu(){
    do{
        clear_terminal();
        cout << "Main menu\n";
        cout << "------ BIENVENIDO A BACKGAMMON ------" << endl;
        cout << "Seleccione una de las siguientes opciones:" << endl;
        cout << "[1] Registrar Jugador" << endl;
        cout << "[2] Establecer turno" << endl;
        cout << "[3] Iniciar Backgammom" << endl;
        cout << "[0] Salir" << endl;
        cout << "Ingrese la opcion deseada: ";
        cin >> op;
        switch (op) {
            case 1:
                register_player();
                break;
            case 2:
                set_turn();
                break;
            case 3:
                init_game();
                break;
            case 0:
                cout << "Gracias por jugar Bagamon" << endl;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
    }while(op != 0);


}