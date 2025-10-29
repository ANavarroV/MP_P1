#ifndef EMPRESA_H
#define EMPRESA_H

#include <Fecha.h>
#include <Contrato.h>
#include <Cliente.h>
#include <ContratoMovil.h>
#include <ContratoTP.h>

class Empresa{

    Cliente *clientes[100];
    int ncli;
    const int nmaxcli;
    Contrato **contratos;
    int ncon;
    int nmaxcon;

    protected: //métodos auxiliares usados por los métodos públicos
        int buscarCliente(long int dni) const; //si no existe devuelve -1 y si existe devuelve
        //la posición del cliente en el array clientes
        int altaCliente(Cliente *c); //añade el cliente apuntado por c al array clientes
        //devuelve la posición donde lo mete (-1 si no cabe)
        void capacidadContratos();

    public:
        Empresa();
        virtual ~Empresa();
        //EL CONTRUCTOR DE COPIA Y EL OPERADOR DE ASIGNACION NO LO IMPLEMENTAMOS
        //PORQUE EXPLICITAMENTE SE INDICA EN LA PRACTICA QUE NO SE HAGA
        void crearContrato();
        bool cancelarContrato(int idContrato); //true si el Contrato existe, false si no
        bool bajaCliente(long int dni); //true si el Cliente existe, false si no
        int descuento (float porcentaje) const; //devuelve a cuantos aplica el descuento
        int nContratosTP() const;
        void cargarDatos();

        void ver() const;

};

#endif // EMPRESA_H
