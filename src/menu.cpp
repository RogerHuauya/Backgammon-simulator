//
// Created by roger on 11/27/2022.
//
#include "../include/menu.h"

using namespace std;

vector<Player> player_list;
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
//me fui a almorzar regreso en un rato ._.
void register_player(){
    string name, password;
    cout<<"Ingrese su usuario: ";
    cin>>name;
    cout<<"Ingrese su contraseña: ";
    cin>>password;
    cout<<"Usuario "<<name<<" creado exitosamente";
    player_list.push_back(Player(name, password, true));
}

void set_turn(){
    cout<<"Jugador 1"<<endl;

}

void init_game(){
    //se supone que va if(validate_number_of_players == true){turno 1} else {return to menu}
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