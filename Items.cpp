#include <iomanip>
#include <cstdlib>
#include "Items.hpp"
using namespace std;

Items::Items(){
    nombre = "";
    puntosDeVida = 0;
}

Items::Items(std::string nombre, int puntosDeVida){
    this->nombre = nombre;
    this->puntosDeVida = puntosDeVida;
}

std::string Items::getNombre(){
    return nombre;
}

int Items::getPuntosDeVida(){
    return puntosDeVida;
}

/*double Items::sumaPuntosDeVida(Guerrero& per1, Items& i1){
    int puntos = per1.getHPactual() + i1.getPuntosDeVida();
    if(puntos > per1.getHPmax()){
        puntos = per1.getHPmax();
    }
    return puntos;
} */

void Items::imprime(){
    cout<<nombre<<" con "<<puntosDeVida<<" puntos de vida\n"<<endl;
}