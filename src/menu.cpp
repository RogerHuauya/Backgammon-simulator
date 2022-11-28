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
    cout<<"Usuario "<<name<<" creado exitosamente" << endl;
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
        game_board.set_player2(nullptr);
        game_board.set_player1(nullptr);
        return;
    }

    int d1,d2,d3,d4;
    d1 = rand()%6+1;
    d2 = rand()%6+1;
    d3 = rand()%6+1;
    d4 = rand()%6+1;
    string ficha1, ficha2;
    cout << "Dados para \"" << game_board.get_player1()->get_username() << "\": "<< d1 << ", " << d2 << endl;
    cout << "Dados para \"" << game_board.get_player2()->get_username() << "\": "<< d3 << ", " << d4 << endl;
    if ((d1+d2)>=(d3+d4)) {
        cout << "El jugador \"" << game_board.get_player1()->get_username() << "\" elige la ficha [X u O]: ";
        cin >> ficha1;
        if(ficha1=="X"){ficha2="O";}
        else if (ficha1 ==  "O"){ficha2 =  "X";}
    }else{
        cout << "El jugador \"" << game_board.get_player2()->get_username() << "\" elige la ficha [X u O]: ";
        cin >> ficha2;
        if(ficha2== "X"){ficha1= "O";}
        else if (ficha2 ==  "O"){ficha1 =  "X";}
    }
    game_board.get_player1()->set_token_type(ficha1[0]);
    game_board.get_player2()->set_token_type(ficha2[0]);

    cout << "Jugador \"" << game_board.get_player1()->get_username() << "\" jugara con la ficha " << game_board.get_player1()->getToken()<<endl;
    cout << "Jugador \"" << game_board.get_player2()->get_username() << "\" jugara con la ficha " << game_board.get_player2()->getToken()<<endl;
}

void init_game(){
    if(validate_number_of_players()){
        game_board.reset_board();
        game_board.init_players();
        game_board.update_table();
        bool finished = false;
        while(!finished) {
            game_board.display_board();
            finished = game_board.play(cout, cin);
            game_board.reset_board();
            game_board.update_table();
            clear_terminal();
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
        //clear_terminal();
    }while(op != 0);


}