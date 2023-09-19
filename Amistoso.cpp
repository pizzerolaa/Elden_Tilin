#include <iomanip>
#include <cstdlib>
#include "Amistoso.hpp"
#include "Personaje.hpp"
#include "Items.hpp"

Amistoso::Amistoso(){
    estatus = 1; //Cambie el status de bool a int para implementar el random fas facil
    historia = " ";
}

Amistoso::Amistoso(std::string nombre, std::string descripcion, int ubicacion, int estatus, std::string historia, Items& item1) : Personaje(nombre, descripcion, ubicacion){
    this->estatus = estatus;
    this->historia = historia;
    this->item1 = item1;
}

bool Amistoso::getEstatus(){
    return estatus;
}

std::string Amistoso::getHistoria(){
    return historia;
}

Items Amistoso::getItems(){
    return item1;
}

std::string Amistoso::imprime(){
    return Personaje::imprime()+"\n"+ "Historia: " + historia;
    
}

int Amistoso::actua(){
    srand(time(NULL));
    estatus = rand() % 2; 
    if (estatus==1){
        std::cout<<getNombre()<<" te contará una historia:\n"<< historia <<std::endl;
        std::cout<<"Te ha regalado "<<item1.getNombre()<<std::endl;
        int HPganado;
        HPganado= item1.getPuntosDeVida();
        return -HPganado;
    }
    else{
        std::cout<<"El personaje "<<getNombre()<<" No esta dispuesto a hablar :("<<std::endl;
        return 0;
    }
}

void Amistoso::recibeInteraccion(int HPganado){
    int HPactual = HPactual + HPganado;
    std::cout<<"Has recuperado "<<HPganado<<" puntos de vida"<<std::endl;
    if (HPactual>100){
        HPactual=100;
    }
    std::cout<<"Tu HP actual es de "<<HPactual<<std::endl;

}