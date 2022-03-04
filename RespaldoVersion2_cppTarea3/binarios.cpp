#include "binarios.h"


Binarios::Binarios(int binario)
{
    this->numero = binario;
}

std::ostream& operator<<(std::ostream &out, const Binarios &n){
    out<<n.numero;
    return out;
}

std::istream& operator>>(std::istream &in, Binarios &n){
    in>>n.numero;
    return in;
}

bool Binarios :: operator==(const Binarios &n1){
    bool n3;
    n3 = this->numero == n1.numero;
    return n3;
}
