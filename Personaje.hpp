#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <string>
#include <iostream>

class Personaje{
    public:
        Personaje();
        Personaje(std::string, std::string, int);
        std::string getNombre();
        void setNombre(std::string);
        std::string getDescripcion();
        void setDescripcion(std::string);
        int getUbicacion();
        void setUbicacion(int);
        virtual std::string imprime();
        virtual int actua() = 0;
        virtual void recibeInteraccion(int) = 0;
        friend std::ostream& operator<<(std::ostream&, Personaje&);
    private:
        std::string nombre;
        std::string descripcion;
        int ubicacion;
};
#endif