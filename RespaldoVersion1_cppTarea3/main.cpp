#include <iostream>
#include "listas.h"
using namespace std;

int main()
{
    Lista<std::string>* cadena = new Lista<std::string>;
    cadena->insertar("paracetamol");
    cadena->insertar("pergamino");
    cadena->insertar("estupefaciente");
    cadena->insertar("ornitontito");
    std::cout<<cadena->tamanio()<<std::endl;
    cadena->mostrar_todo();
    cadena->modificar(1, "beluga");
    cadena->eliminar(0);
    cadena->mostrar_todo();
    std::cout<<"\n\n";
    cadena->purga();
    std::cout<<cadena->tamanio()<<std::endl;
}
