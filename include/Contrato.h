#ifndef CONTRATO_H
#define CONTRATO_H

#include <iostream>
#include <Fecha.h>

using namespace std;

class Contrato{

    static int contador;
    const int idContrato;
    long int dniContrato;
    Fecha fechaContrato;

    public:
        Contrato(const long int dni, const Fecha &fecha);
        virtual ~Contrato();

        int getId() const;
        long int getDni() const;

        void setDni(long int dni);

        void ver();

};

#endif // CONTRATO_H
