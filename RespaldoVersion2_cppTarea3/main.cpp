#include <Listas.h>
#include <iostream>
#include "binarios.h"

void pruebas();

int main()
{
    pruebas();
    return 0;
}

void pruebas(){
    Binarios b;
    Lista<class Binarios> cadena;

    cadena.insertar(4);
    cadena.insertar(8);
    cadena.insertar(16);
    cadena.mostrar_todo();
    std::cout<<cadena[1]<<"\n";
}
