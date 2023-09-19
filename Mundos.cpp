#include <iomanip>
#include <cstdlib>
#include "Mundos.hpp"
using namespace std;

Mundos::Mundos(){
    nombre = "";
    mundoSig = "";
    descripcion = "";
}

Mundos::Mundos(string nombre, string mundoSig, string descripcion, Items& item1){
    this->nombre = nombre;
    this->mundoSig = mundoSig;
    this->descripcion = descripcion;
    this->item1 = item1;
}

string Mundos::getNombre(){
    return nombre;
}


string Mundos::getMundoSig(){
    return mundoSig;
}

string Mundos::getDescripcion(){
    return descripcion;
}

void Mundos::imprime(){
    cout <<"Te encuentras en "<< nombre << endl;
    cout <<"Descripcion:\n"<< descripcion << endl;
    cout <<"El siguiente nivel es en "<< mundoSig <<endl;
    cout <<"El item que hay en este mundo es: "<< endl;
    item1.imprime();
}