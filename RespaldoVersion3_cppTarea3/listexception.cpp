#include "listexception.h"

ListException::ListException(int codigo)
{
    this->mensaje = "Error de lista :";
    switch(codigo){
    case LISTA_VACIA:
        this->mensaje += "Lista vacia";
        break;
    case POSICION_INVALIDA:
        this->mensaje += "Posicion invalida";
        break;
    case ERROR_MEMORIA:
        this->mensaje += "No se pudo reservar memoria";
        break;
    default:
        this->mensaje += "Desconocido";
        break;
    }
}

const char *ListException::what() const throw()
{
    return this->mensaje.c_str();
}
