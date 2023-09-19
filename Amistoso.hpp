#include <string>
#include "Personaje.hpp"
#include "Items.hpp"

class Amistoso : public Personaje{
    public:
        Amistoso();
        Amistoso(std::string, std::string, int, int, std::string, Items&);
        bool getEstatus();
        std::string getHistoria();
        Items getItems();
        std::string imprime() override;
        int actua();
        void recibeInteraccion(int);
        
    private:
        bool estatus;
        std::string historia;
        Items item1;
};