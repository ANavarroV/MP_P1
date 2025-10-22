#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <cstring>
#include <Fecha.h>

using namespace std;

class Cliente{

    long int dni;
    char *nombre;
    Fecha fechaAlta;

    public:
        Cliente(long int d, const char nom[], const Fecha &f);
        Cliente(const Cliente &otro);
        virtual ~Cliente();

        long int getDni() const;
        char* getNombre() const;
        Fecha getFecha() const;

        void setNombre(char nom[]);
        void setFecha(Fecha f);

        bool operator==(const Cliente &otro) const;
        Cliente& operator=(const Cliente &otro);

};

ostream& operator<<(ostream &out, const Cliente &c);

#endif // CLIENTE_H
