#include <iomanip>
#include "Personaje.hpp"
using namespace std;

Personaje::Personaje(){
    nombre = "";
    descripcion = "";
}

Personaje::Personaje(std::string nombre, std::string descripcion, int ubicacion1){
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->ubicacion = ubicacion1;
}

std::string Personaje::getNombre(){
    return nombre;
}

void Personaje::setNombre(std::string nombre){
    this->nombre = nombre;
    std::cout<<"Nombre del personaje: "<<nombre<<endl;
}

std::string Personaje::getDescripcion(){
    return descripcion;
}

int Personaje::getUbicacion(){
    return ubicacion;
}

void Personaje::setUbicacion(int ubicacion){
    this->ubicacion = ubicacion;
    std::cout<<"Ubicacion del personaje: Planeta "<<ubicacion<<endl;
}

std::string Personaje::imprime(){
    return "Nombre del personaje: " + getNombre()+ "\n" + "Descripcion del personaje: " + getDescripcion()+ "\n" + "Ubicacion del personaje: Planeta " + "Ubicacion del personaje: Planeta " + to_string(getUbicacion())+ "\n";
}
std::ostream& operator<<(std::ostream& salida, Personaje& per1){
    salida << per1.imprime();
    return salida;
}
