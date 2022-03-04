#include <Listas.h>
#include <iostream>
#include <math.h>
#include "binarios.h"

#define NUMEROS_BINARIOS 10

void prueba_binarios();

int main()
{
    prueba_binarios();
    return 0;
}

void prueba_binarios(){

    Lista<class Binarios> listaBin;

    try{
        listaBin.mostrar_todo();
    }catch(ListException &e){
        std::cerr<<e.what()<<std::endl;
    }

    if(listaBin.vacia())
        std::cout<<"La lista esta vacia, no contiene elementos"<<"\n";
    else
        std::cout<<"La lista NO esta vacia, contiene elementos"<<"\n";

    for(int i=0; i<NUMEROS_BINARIOS; i++){
        try{
            listaBin.insertar(pow(2,i));
        }catch(ListException &e){
            std::cerr<<e.what()<<std::endl;
        }
    }

    try{
        listaBin.mostrar_todo();
    }catch(ListException &e){
        std::cerr<<e.what()<<std::endl;
    }

    try{
        listaBin.modificar(15, 8);
    }catch(ListException &e){
        std::cerr<<e.what()<<std::endl;
    }

    try{
        listaBin.insertar_en(20, 255);
    }catch(ListException &e){
        std::cerr<<e.what()<<std::endl;
    }

    try{
        listaBin.purga();
    }catch(ListException &e){
        std::cerr<<e.what()<<std::endl;
    }

    try{
        if(listaBin.buscar(30) != -1)
            std::cout<<"Se logro encontrar el elemento"<<"\n";
        else
            std::cout<<"NO se logro encontrar el elemento"<<"\n";
    }catch(ListException &e){
        std::cerr<<e.what()<<std::endl;
    }

    try {
        listaBin.tamanio();
    }catch(ListException &e){
        std::cerr<<e.what()<<std::endl;
    }

    try {
    std::cout<<listaBin[60]<<"\n";
    }catch(ListException &e){
        std::cerr<<e.what()<<std::endl;
    }

    try {
        listaBin.tomar_primero();
    }catch(ListException &e){
        std::cerr<<e.what()<<std::endl;
    }

    try {
    std::cout<<listaBin[0]<<"\n";
    }catch(ListException &e){
        std::cerr<<e.what()<<std::endl;
    }

    for(int i=0; i<NUMEROS_BINARIOS; i++){
        try{
            listaBin.insertar(pow(2,i));
        }catch(ListException &e){
            std::cerr<<e.what()<<std::endl;
        }
    }

    try {
        listaBin.eliminar(14);
    }catch(ListException &e){
        std::cerr<<e.what()<<std::endl;
    }

}
