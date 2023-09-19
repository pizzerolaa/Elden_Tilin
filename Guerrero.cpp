#include <iomanip>
#include <cstdlib>
#include "Guerrero.hpp"
#include "Personaje.hpp"
//#include "Items.hpp"

Guerrero::Guerrero(){
    HPmax = 100;
    HPactual = 0;
    ataque = 6;
    estado = 1; //Cambie el status de bool a int para implementar el random fas facil
    jugador = false;
}

Guerrero::Guerrero(std::string nombre, std::string descripcion, int ubicacion, int HPmax, int HPactual, int ataque, int estado,bool jugador) : Personaje(nombre, descripcion, ubicacion){
    this->HPmax = HPmax;
    this->HPactual = HPactual;
    this->ataque = ataque;
    this->estado = estado;
    this->jugador = jugador;
}

int Guerrero::getHPmax(){
    return HPmax;
}

int Guerrero::getHPactual(){
    return HPactual;
}

int Guerrero::getAtaque(){
    for(int i = 0; i < 3; i++){
        if(estado == true){
            srand(time(NULL));
            ataque =rand() % 15 + 10;
        }
    }
    return ataque;
}

bool Guerrero::getEstado(){
    return estado;
}

void Guerrero::setHPactual(int HPactual){
    this->HPactual = HPactual;
}

int Guerrero::calculaHP(){
    return HPmax - HPactual;
}

std::string Guerrero::barraVida(){
    std::string barra = "";
    int porcentaje = (HPactual * 100) / HPmax;
    for(int i = 0; i < 20; i++){
        if (i < HPactual/5){    
            barra += "%";
        }
        else{
            barra += "=";
        }
    }
    return barra;
}

std::string Guerrero::imprime(){
    return Personaje::imprime() + "\nHP:" + Guerrero::barraVida();  // Llamada a la funcion imprime de la clase Personaje
     // Llamada a la funcion barraVida de la clase Guerrero
}

int Guerrero::actua(){
    srand(time(NULL));
    int ATK = 10 + rand() % (ataque);
    return ATK;
}

void Guerrero::recibeInteraccion(int ATK){
    HPactual -= ATK;
    std::cout<<getNombre()<<" recibe "<<ATK<<" puntos de daño."<<std::endl;
    if(HPactual <= 0){
        estado = 0;
        std::cout<<getNombre()<<" ha muerto."<<std::endl;
        if (jugador == true){
            std::cout<<"GAME OVER"<<std::endl;
            exit(0);
        }
    }   
    else{
        std::cout<<getNombre()<<" tiene "<<HPactual<<" puntos de vida restantes."<<std::endl;
        std::cout<<Guerrero::barraVida()<<std::endl;
    }
}