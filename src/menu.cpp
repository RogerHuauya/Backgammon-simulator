//
// Created by roger on 11/27/2022.
//
#include "../include/menu.h"

using namespace std;

vector<Player> player_list;
Board game_board;
void menu(){
    int op;
    cout<<"Main menu\n";
    cout<<"−−−−−−− BIENVENIDO A BACKGAMMON −−−−−−−"<<endl;
    cout<<"Seleccione una de las siguientes opciones:"<<endl;
    cout<<"[1] Registrar Jugador"<<endl;
    cout<<"[2] Establecer turno"<<endl;
    cout<<"[3] Iniciar Backgammom"<<endl;
    cout<<"[0] Salir"<<endl;
    cout<<"Ingrese la opcion deseada: ";
    cin>> op;
    switch(op){
        case 1:  register_player(); break;
    }
};


void register_player(){
    string name, password;
    cout<<"Ingrese su usuario: ";
    cin>>name;
    cout<<"Ingrese su contraseña: ";
    cin>>password;
    cout<<"Usuario "<<name<<" creado exitosamente";
    player_list.push_back(Player(name, password));
}

void set_turn(){
    string name,name2, pass2, pass;
    bool ans1 = false;
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
        cout << "¡Datos incorrectos!" << endl << "Por favor vuelva a ingresar su usuario";
        return;
    }

    cout<<"Jugador 2"<<endl;
    cout<<"Ingrese su usuario: ";
    cin>>name;
    cout<<"Ingrese su contrasena: ";
    cin>>pass;
    for(int i = 0; i < player_list.size(); i ++){
        if(player_list[i].get_username() == name) {
            ans = player_list[i].login(pass);
            if (ans) {
                game_board.set_player2(&player_list[i]);
            }
        }
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