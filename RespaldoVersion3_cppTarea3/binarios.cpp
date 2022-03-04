#include "binarios.h"


Binarios::Binarios(int binario)
{
    this->numero = binario;
}

std::ostream& operator<<(std::ostream &salida, const Binarios &n){
    salida<<n.numero;
    return salida;
}

bool Binarios :: operator==(const Binarios &num1){
    bool num2 = this->numero == num1.numero;
    return num2;
}
