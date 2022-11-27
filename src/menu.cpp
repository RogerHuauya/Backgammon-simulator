//
// Created by roger on 11/27/2022.
//
#include "../include/menu.h"

using namespace std;

vector<Player> player_list;
Board game_board;


void register_player(){
    string name, password;
    cout<<"Ingrese su usuario: ";
    cin>>name;
    cout<<"Ingrese su contrasena: ";
    cin>>password;
    cout<<"Usuario "<<name<<" creado exitosamente";
    player_list.emplace_back(name, password);
}

void set_turn(){
    string name, pass;
    bool ans1 = false;
    bool ans2 = false;
    cout<<"Jugador 1"<<endl;
    cout<<"Ingrese su usuario: ";
    cin>>name;
    cout<<"Ingrese su contrasena: ";
    cin>>pass;
    for(auto & i : player_list){
        if(i.get_username() == name) {
            ans1 = i.login(pass);
            if (ans1) {
                game_board.set_player1(&i);
            }
        }
    }
    if(!ans1){
        cout << "¡Datos incorrectos!" << endl << "Por favor vuelva a ingresar su usuario" << endl;
        return;
    }

    cout<<"Jugador 2"<<endl;
    cout<<"Ingrese su usuario: ";
    cin>>name;
    cout<<"Ingrese su contrasena: ";
    cin>>pass;
    for(auto & i : player_list){
        if(i.get_username() == name) {
            ans2 = i.login(pass);
            if (ans2) {
                game_board.set_player2(&i);
            }
        }
    }
    if(!ans2){
        cout << "¡Datos incorrectos!" << endl << "Por favor vuelva a ingresar su usuario";
        return;
    }

}

void init_game(){
    if(validate_number_of_players()){
        register_player();
        cout<<"Dados para Jugador 1: "<<endl;
    } else {cout<<"Regresar al menu";}
}

bool validate_number_of_players(){
    if(player_list.size()<2){
        return true;
    }
    else{
        return false;
    }
}

void clear_terminal(){
    system("cls");
}


void menu(){
    int op;
    do{
        cout << "Main menu\n";
        cout << "−−−−−−− BIENVENIDO A BACKGAMMON −−−−−−−" << endl;
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
                /*
                reset_board();

                update_table();

                display_board();
                 */
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
        clear_terminal();
    }while(op != 0);
};