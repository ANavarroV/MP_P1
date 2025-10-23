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

Contrato::Contrato(const Contrato &o): idContrato(contador++),fechaContrato(o.fechaContrato){
    dniContrato = o.dniContrato;
}

long int Contrato::getDniContrato() const{
    return dniContrato;
}

int Contrato::getIdContrato() const{
    return idContrato;
}

Fecha Contrato::getFechaContrato() const{
    return fechaContrato;
}

void Contrato::setDniContrato(long int dni){
    dniContrato = dni;
}

void Contrato::setFechaContrato(Fecha f){
    fechaContrato = f;
}

void Contrato::ver(){
    cout << getDniContrato() << " (" << getIdContrato() << " - ";
    fechaContrato.ver();
    cout << ")";
}

ostream& operator<<(ostream &out, const Contrato &c){

    out << c.getDniContrato() << " (" << c.getIdContrato() << " - " << c.getFechaContrato() << ")";

    return out;
}

