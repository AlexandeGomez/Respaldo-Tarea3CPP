#ifndef LISTAS_H
#define LISTAS_H

#include <iostream>
#include "listexception.h"
/* ------------------------------
                  NODO
   ------------------------------ */
template <class T>
class Nodo
{
private:
    Nodo<T>* address;
    T data;
public:
    Nodo();
    void set_data(T);
    void set_address(Nodo<T>*);
    T get_data();
    Nodo<T>* get_address();
};
//---------------- [Constructor]
template <class T>
Nodo<T>::Nodo()
{
    this->address = NULL;
}
//---------------- [asignar dato al nodo]
template <class T>
void Nodo<T>::set_data(T _data){
    this->data = _data;
}
//---------------- [asignar direccion al nodo]
template <class T>
void Nodo<T>::set_address(Nodo<T> *_address){
    this->address = _address;
}
//---------------- [devolver direccion del nodo]
template <class T>
T Nodo<T>::get_data(){
    return this->data;
}

template <class T>
Nodo<T>* Nodo<T>::get_address(){
    return this->address;
}

/* ------------------------------------
                    LISTA
   ------------------------------------ */
template <class T>
class Lista
{
private:
    Nodo<T>* header;

    void set_header(Nodo<T>*);
    Nodo<T>* get_header();

    Nodo<T>* search_address(int);
    Nodo<T>* get_ultimo();
    int check_position(int);
public:
    Lista();
    void mostrar_todo(); //check
    void purga(); //check
    bool vacia(); //check
    int modificar(int, T); // check
    int insertar_en(int, T); //check
    int insertar(T); //check
    int buscar(T); //check
    int eliminar(int); //check
    int tamanio(); // check
    T tomar_primero(); // check
    T tomar(int); // check
    T operator [] (int indice);
};
//---------------- [Constructor]
template<class T>
Lista<T>::Lista()
{
    this->header = NULL;
}
//---------------- [asignar direccion a la cabeza de lista]
template <class T>
void Lista<T>::set_header(Nodo<T>* _address){
    this->header = _address;
}
//---------------- [obtener direccion de la cabeza]
template <class T>
Nodo<T>* Lista<T>::get_header(){
    return this->header;
}
//---------------- [metodo evalua si la lista esta vacia]
template<class T>
bool Lista<T>::vacia(){
    if(this->header)
        return false;
    else
        return true;
}
//---------------- [metodo que nos regresa la direccion del nodo en una posicion]
template <class T>
Nodo<T>* Lista<T>::search_address(int posicion){
    int contador = 0;
    if(this->vacia())
        return NULL;
    for(Nodo<T>* aux = this->get_header(); aux!=NULL; aux = aux->get_address(), contador++){
        if(contador==posicion)
            return aux;
    }
    return NULL;
}
//---------------- [metodo para conseguir la direccion del ultimo nodo de la lista]
template <class T>
Nodo<T>* Lista<T>::get_ultimo(){
    Nodo<T>* direccion = NULL;
    if(this->vacia()){
        return NULL;
    }
    direccion = this->get_header();
    while(direccion->get_address()!=NULL){
        direccion = direccion->get_address();
    }
    return direccion;
}
//---------------- [metodo para evaluar numero de elementos de lista y sacar excepciones]
template <class T>
int Lista<T>::check_position(int posicion){
    if(this->vacia()){
        throw ListException(ListExceptionCodigo::LISTA_VACIA);
        return -1;
    }
    else if(posicion < 0 || posicion > this->tamanio()){
        throw ListException(ListExceptionCodigo::POSICION_INVALIDA);
        return -1;
    }
    return 1;
}

/*
                        METODOS PROPIOS DEL EJERCICIO
*/
template<class T>
int Lista<T>::insertar(T dato){
    Nodo<T>* nuevo = NULL;
    try{
        nuevo = new Nodo<T>;
        nuevo->set_data(dato);
    }catch (std::bad_alloc &e) {
        throw ListException(ListExceptionCodigo::ERROR_MEMORIA);
        return -1;
    }
    if(this->vacia())
        this->set_header(nuevo);
    else
        this->get_ultimo()->set_address(nuevo);
    return 1;
}

template<class T>
int Lista<T>::tamanio(){
    int cont = 0;
    Nodo<T>* direccion = NULL;
    if(this->vacia()){
        return cont;
    }
    direccion = this->get_header();
    while(direccion!=NULL){
        direccion = direccion->get_address();
        cont++;
    }
    return cont;
}

template <class T>
int Lista<T>::insertar_en(int pos, T dato){
    Nodo<T>* direccion = NULL;
    Nodo<T>* anterior = NULL;
    if(this->check_position(pos) != -1){
        try{
            direccion = new Nodo<T>;
            direccion->set_data(dato);
        }catch (std::bad_alloc &e) {
            throw ListException(ListExceptionCodigo::ERROR_MEMORIA);
            return -1;
        }
        if(this->vacia()){
            this->set_header(direccion);
        }
        else if(pos==0){
            direccion->set_address(this->get_header());
            this->set_header(direccion);
        }
        else{
            anterior = this->search_address(pos-1);
            direccion->set_address(anterior->get_address());
            anterior->set_address(direccion);
        }
    }
    return -1;
}

template <class T>
void Lista<T>::mostrar_todo(){
    Nodo<T>* direccion = NULL;
    int size = 0;
    if(this->vacia())
        throw ListException(ListExceptionCodigo::LISTA_VACIA);
    direccion = this->get_header();
    size = this->tamanio();
    for(int i=0; i<size; i++){
        std::cout<<i<<".- "<<direccion->get_data()<<std::endl;
        direccion = direccion->get_address();
    }
}

template <class T>
int Lista<T>::modificar(int posicion, T dato){
    Nodo<T>* direccion = NULL;
    if(this->check_position(posicion) != -1){
        direccion = this->search_address(posicion);
        direccion->set_data(dato);
        return 1;
    }
    return -1;
}

template <class T>
T Lista<T>::tomar(int posicion){
    Nodo<T>* direccion = NULL;
    if(this->check_position(posicion) != -1){
        direccion = this->search_address(posicion);
        return direccion->get_data();
    }
    return -1;
}

template <class T>
T Lista<T>::tomar_primero(){
    return tomar(0);
}

template <class T>
int Lista<T>::buscar(T dato){
    int contador = 0;
    if(this->vacia()){
        throw ListException(ListExceptionCodigo::LISTA_VACIA);
        return -1;
    }
    for(Nodo<T>* aux = this->get_header(); aux->get_address()!=NULL; aux = aux->get_address(), contador++){
        if(aux->get_data()==dato){
            return contador;
        }
    }
    return -1;
}

template <class T>
int Lista<T>::eliminar(int posicion){
    Nodo<T>* direccion = NULL;
    Nodo<T>* anterior = NULL;
    if(this->check_position(posicion) != -1){
        if(posicion == 0){
            direccion = this->get_header();
            this->set_header(direccion->get_address());
            delete direccion;
            return 1;
        }
        direccion = search_address(posicion);
        anterior = search_address(posicion-1);
        anterior->set_address(direccion->get_address());
        delete direccion;
        return 1;
    }
    return -1;
}

template <class T>
void Lista<T>::purga(){
    int tamanio = 0;
    if(this->vacia())
        throw ListException(ListExceptionCodigo::LISTA_VACIA);
    tamanio = this->tamanio();
    for(int i=tamanio; i > 0; i--){
        this->eliminar(i-1);
    }
}

template <class T>
T Lista<T>::operator[](int indice){
    return this->tomar(indice);
}

#endif // LISTAS_H
