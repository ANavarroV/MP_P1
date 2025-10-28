#ifndef CONTRATOMOVIL_H
#define CONTRATOMOVIL_H

#include <iostream>
#include <cstring>
#include <Contrato.h>

class ContratoMovil: public Contrato{

    char* nacionalidad;
    float precioMin;
    int minHablados;

    public:
        ContratoMovil(long int dni, const Fecha &f, float pM, int mH, const char nac[]);
        virtual ~ContratoMovil();

        ContratoMovil(const ContratoMovil &otro);

        char* getNacionalidad() const;
        float getPrecioMinuto() const;
        int getMinutosHablados() const;

        void setNacionalidad(char nac[]);
        void setPrecioMinuto(float pM);
        void setMinutosHablados(int mH);
        float factura() const;

        void ver();

};

ostream& operator<<(ostream &out, ContratoMovil &cM);

#endif // CONTRATOMOVIL_H
