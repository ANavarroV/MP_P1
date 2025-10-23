#ifndef CONTRATOTP_H
#define CONTRATOTP_H

#include <iostream>
#include <cstring>
#include <Contrato.h>

class ContratoTP: public Contrato{

    static float precioTP;
    static int limiteMinutos;
    int minHablados;

    public:
        ContratoTP(long int dni, const Fecha &f, int mH);
        virtual ~ContratoTP();

        static int getLimiteMinutos();
        static float getPrecio();
        int getMinutosHablados() const;

        float factura();
        void setMinutosHablados(int mH);
        static void setTarifaPlana(int m, float p);

        void ver();
};

ostream& operator<<(ostream &out, ContratoTP &cTP);


#endif // CONTRATOTP_H
