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
        Contrato(const Contrato& o);

        int getIdContrato() const;
        long int getDniContrato() const;
        Fecha getFechaContrato() const;

        void setDniContrato(long int dni);
        void setFechaContrato(Fecha f);

        virtual void ver(); // Comportamiento polimórfico
        virtual float factura() const = 0; // Método virtual puro (Clase abstracta)


};

ostream& operator<<(ostream &s, const Contrato &c);

#endif // CONTRATO_H
