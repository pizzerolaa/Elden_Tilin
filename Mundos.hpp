#include <string>
#include "Items.hpp"

class Mundos{
    public:
        Mundos();
        Mundos(std::string, std::string, std::string, Items&);
        std::string getNombre();
        std::string getDescripcion();
        std::string getMundoSig();
        void imprime();
    private:
        std::string nombre;
        std::string mundoSig;
        std::string descripcion;
        Items item1;
};