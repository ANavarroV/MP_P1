#include "Contrato.h"
#include <iostream>

using namespace std;

int Contrato::contador = 1;

Contrato::Contrato(long int dni, const Fecha &f):idContrato(contador), fechaContrato(f){
    dniContrato = dni;
    contador++;
}

Contrato::~Contrato(){
    //dtor
}

long int Contrato::getDni() const{
    return dniContrato;
}

int Contrato::getId() const{
    return idContrato;
}

void Contrato::setDni(long int dni){
    dniContrato = dni;
}

void Contrato::ver(){
    cout << getDni() << " (" << getId() << " - ";
    fechaContrato.ver();
    cout << ")" << endl;
}
