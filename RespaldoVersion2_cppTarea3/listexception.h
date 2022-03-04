#ifndef LISTEXCEPTION_H
#define LISTEXCEPTION_H

#include <exception>
#include <iostream>

enum ListExceptionCodigo{
  LISTA_VACIA,
  POSICION_INVALIDA,
  ERROR_MEMORIA
};

class ListException : public std::exception
{
private:
    std::string mensaje;
public:
    ListException(int);
    const char* what() const throw();
};

#endif // LISTEXCEPTION_H
