#pragma once
//#include "Guerrero.hpp"
#include <iostream>

class Items{
    public:
        Items();
        Items(std::string, int);
        std::string getNombre();
        int getPuntosDeVida();
        void imprime();
        //double sumaPuntosDeVida(Guerrero&, Items&);
    private:
        std::string nombre;
        int puntosDeVida;
};