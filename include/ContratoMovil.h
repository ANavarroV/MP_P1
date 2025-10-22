#ifndef CONTRATOMOVIL_H
#define CONTRATOMOVIL_H

#include <Contrato.h>
#include <Fecha.h>

class ContratoMovil: public Contrato{

    char* nacionalidad;
    float precioMin;
    int minHablados;

    public:
        ContratoMovil(long int dni, const Fecha &f, float pM, int mH);
        virtual ~ContratoMovil();

};

#endif // CONTRATOMOVIL_H
