#include <stdio.h>
#include <time.h>
#include <wchar.h>
#include <locale.h>
#include <vector>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <stdexcept>
#include "Personaje.hpp"
#include "Guerrero.hpp"
#include "Amistoso.hpp"
#include "Items.hpp"
#include "Mundos.hpp"
using namespace std;

int main() {
  setlocale(LC_ALL, "");
  vector<Personaje*> personajes;
  vector<Mundos*> mundos;
  vector<Items*> items;

  items.push_back(new Items("Calabaza Curativa", 20));
  items.push_back(new Items("Pocion de Mana", 15));
  items.push_back(new Items("", 0));

  mundos.push_back(new Mundos("Alderaan", "Cybertron", "Cuenta con amplias y ricas praderas. Su flora y fauna es de las\nmás variadas, llegando a contar más de 8000 especies vegetales,\nmuchas con flores", *items[0]));
  mundos.push_back(new Mundos("Cybertron", "Terrax", "Es un planeta de metal, hogar de los Autobots y los Decepticons.\nEs el planeta natal de seres muy avanzados y poderosos", *items[1]));
  mundos.push_back(new Mundos("Terrax", "GuinarX", "Es un planeta construido por la Estrella de la Muerte, hogar de la\nprincesa más poderosa de la galaxia y de la Casa Real de Alderaan", *items[2]));

  cout<<"<-----------------BIENVENIDO A ELDEN TILIN----------------->"<<endl;
  string mainchar;
  cout<<"Ingrese el nombre de su personaje: "; cin>>mainchar;

  Personaje *mainChar = new Guerrero(mainchar, "Guerrero de alto calibre, sanguinario y bastante ágil", 0, 100, 100, 30, 1, true);
  Personaje *per1 = new Guerrero("Dante", "Dante es un híbrido (semi-demonio) el cual ha dedicado gran parte de su vida a eliminar\ndemonios y demás criaturas infernales.", 100 , 100, 100, 15, 1, false);
  Personaje *per2 = new Amistoso("Doomfist", "Líder innato y guerrero de élite, perdió el brazo derecho durante la Crisis Ómnica,\ncuando se unió a las filas de Talon.", 101 , 1, "Después de la derrota de Akinjide, el guante Doomfist pasó a ser utilizado por otro personaje, conocido como el 'Sucedáneo'.\nEsta historia podría seguir al Sucedáneo mientras lucha por mantenerse fiel a los ideales de Akinjide mientras lucha contra la corrupción y \nel poder dentro de Talon. La trama podría centrarse en su lucha interna y cómo trata de liberarse del control de Talon y recuperar el legado original de Doomfist.", *items[0]);
  Personaje *per3 = new Guerrero("Travis Scott", "Famoso guerrero de la noche, siempre anda acompañado de su fiel camarada Cactus Jack", 102 , 100, 100, 15, 1, false);

  personajes.push_back(per1);
  personajes.push_back(per2);
  personajes.push_back(per3);

  //Definimos los punteros de los personajes
  Guerrero* ptrMC = dynamic_cast<Guerrero*>(mainChar);
  Guerrero* ptrP1 = dynamic_cast<Guerrero*>(per1);
  Guerrero* ptrP3 = dynamic_cast<Guerrero*>(per3);

  cout<<endl;
  cout<<"BIENVENIDO DE NUEVO "<<ptrMC->getNombre()<<"!!!"<<endl;
  int opcion = 0;
  cout<<"Que desea hacer?"<<endl;
  cout<<"1. Jugar"<<endl;
  cout<<"2. Salir"<<endl;
  cout<<"Esperando respuesta... "; cin>>opcion;
  cout<<" "<<endl;
  while(true){
    try{
      if(opcion == 1){
        break;
      }
      else if(opcion == 2){
        cout<<"Gracias por jugar, vuelva pronto..."<<endl;
        exit(0);
      }
      else if(opcion != 1 || opcion != 2){
        throw runtime_error("Opcion no valida");
      }
    }
    catch(exception& exp)
    {
      cout<<"Opcion no valida se presento el error: "<<exp.what()<<endl;
      cout<<"¿Qué desea hacer?\n1. Jugar\n2. Salir"<<endl;
      cout<<"Esperando respuesta... "; cin>>opcion;
      cout<<" "<<endl;
    }
  }

  this_thread::sleep_for(chrono::seconds(1));
  cout<<"Has podido avanzar hasta aquí, pero para salir de aquí tendras que pelear,\naquí tienes un poco de informacion sobre el lugar al que te diriges..."<<endl;
   this_thread::sleep_for(chrono::seconds(1));
  mundos[0]->imprime();
   this_thread::sleep_for(chrono::seconds(1));

  cout<<"BIENVENIDO PRIMER NIVEL"; cout<<"."; this_thread::sleep_for(chrono::seconds(1)); cout<<"."; this_thread::sleep_for(chrono::seconds(1)); cout<<"."; this_thread::sleep_for(chrono::seconds(1));
  cout<<endl;
  cout<<ptrP1->imprime()<<endl;
  cout<<"Ingrese cualquier tecla para continuar... "; cin.ignore(); cin.get();
  cout<<endl;
  while(true){
    cout<<ptrMC->getNombre()<<" ataca..."<<endl;
    ptrP1->recibeInteraccion(ptrMC->actua());
    if (ptrP1->getHPactual()<=0){
      cout<<"Felicidades, has derrotado al enemigo!!\nAvanzas al sig. nivel..."<<endl;
      break;
    }
    cout<<"Ingrese cualquier tecla para continuar... "; cin.ignore(); cin.get();
    cout<<endl;
    cout<<ptrP1->getNombre()<<" ataca..."<<endl;
    ptrMC->recibeInteraccion(ptrP1->actua());
    if (ptrMC->getHPactual()<=0){
      break;
    }
     this_thread::sleep_for(chrono::seconds(1));
    cout<<"Ingrese cualquier tecla para continuar... "; cin.ignore(); cin.get();
    cout<<endl;
  }

//-----------------------Segundo Mundo-----------------------//
  cout<<"Presione cualquier tecla para continuar... "; cin.ignore(); cin.get();
  cout<<endl;
  this_thread::sleep_for(chrono::milliseconds(800));
  cout<<"SÉ BIENVENIDO AL SEGUNDO NIVEL..."<<endl;
  cout<<"Presione cualquier tecla para continuar... "; cin.ignore(); cin.get();
  cout<<endl;
  this_thread::sleep_for(chrono::milliseconds(700));
  cout<<"Te dejamos un poco de información sobre este mundo, espero te sea de utilidad!:)"<< endl;
  mundos[1]->imprime();
  cout<<" "<<endl;
  cout<<"Presione cualquier tecla para continuar... "; cin.ignore(); cin.get();

  //Empieza la interaccion con el personaje amistoso
  Amistoso* ptrP2 = dynamic_cast<Amistoso*>(per2);
  ptrMC->recibeInteraccion(ptrP2->actua());

//-----------------------Tercer Mundo-----------------------//
  cout<<" "<<endl;
  cout<<"BIENVENIDO AL TERCER NIVEL"; cout<<"."; this_thread::sleep_for(chrono::seconds(1)); cout<<"."; this_thread::sleep_for(chrono::seconds(1)); cout<<"."; this_thread::sleep_for(chrono::seconds(1));
  cout<<endl;
  cout<<ptrP3->imprime()<<endl;
  cout<<"Ingrese cualquier tecla para continuar... "; cin.ignore(); cin.get();
  cout<<endl;
  while(true){
    cout<<ptrMC->getNombre()<<" ataca..."<<endl;
    ptrP3->recibeInteraccion(ptrMC->actua());
    if (ptrP3->getHPactual()<=0){
      cout<<"Felicidades, has derrotado al enemigo!!"<<endl;
      cout<<"FIN DEL JUEGO"<<endl;
      cout<<"HAS GANADO!! CONGRATULATIONS!!"<<endl;
      exit(0);
    }
    cout<<"Ingrese cualquier tecla para continuar... "; cin.ignore(); cin.get();
    cout<<endl;
    cout<<ptrP3->getNombre()<<" ataca..."<<endl;
    ptrMC->recibeInteraccion(ptrP3->actua());
    if (ptrMC->getHPactual()<=0){
      break;
    }
     this_thread::sleep_for(chrono::seconds(1));
    cout<<"Ingrese cualquier tecla para continuar... "; cin.ignore(); cin.get();
    cout<<endl;
  }
}
  
