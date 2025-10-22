#ifndef CONTRATOTP_H
#define CONTRATOTP_H

#include <Contrato.h>

class ContratoTP: public Contrato{

    static float precioTP;
    int minHablados;

    public:
        ContratoTP(long int dni, const Fecha &f, int mH);
        virtual ~ContratoTP();

        int getLimiteMinutos();
        static float getPrecio();
};

#endif // CONTRATOTP_H
