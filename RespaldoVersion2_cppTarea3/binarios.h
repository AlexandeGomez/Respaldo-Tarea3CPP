#ifndef BINARIOS_H
#define BINARIOS_H
#include <iostream>

class Binarios
{
private:
    int numero;
public:
    Binarios(int binario = 2);
    friend std::ostream& operator<<(std::ostream &, const Binarios &);
    friend std::istream& operator>>(std::istream &, Binarios &);
    bool operator==(const Binarios &);
};

#endif // BINARIOS_H
