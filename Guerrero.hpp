#include <string>
#include "Personaje.hpp"

class Guerrero : public Personaje{
    public:
        Guerrero();
        Guerrero(std::string, std::string, int, int, int, int, int, bool);
        int getHPmax();
        int getHPactual();
        int getAtaque();
        bool getEstado();
        void setHPactual(int);
        int calculaHP();
        std::string barraVida();
        std::string imprime() override;
        int actua();
        void recibeInteraccion(int);
    private:
        int HPmax;
        int HPactual;
        int ataque;
        int estado;
        bool jugador;
};