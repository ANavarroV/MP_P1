#include "ContratoMovil.h"

ContratoMovil::ContratoMovil(long int dni, const Fecha &f, float pM, int mH, const char nac[]): Contrato(dni, f){

    nacionalidad = new char[strlen(nac)+1];
    strcpy(nacionalidad, nac);
    precioMin = pM;
    minHablados = mH;
}

ContratoMovil::~ContratoMovil(){
    delete [] nacionalidad;
}

ContratoMovil::ContratoMovil(const ContratoMovil &otro) : Contrato(otro){

    nacionalidad = new char[strlen(otro.nacionalidad)+1];
    strcpy(nacionalidad, otro.nacionalidad);

    precioMin = otro.precioMin;
    minHablados = otro.minHablados;

}

char* ContratoMovil::getNacionalidad() const{

    return nacionalidad;
}

float ContratoMovil::getPrecioMinuto() const{

    return precioMin;
}

int ContratoMovil::getMinutosHablados() const{

    return minHablados;
}

void ContratoMovil::setNacionalidad(char nac[]){
    delete [] nacionalidad;
    nacionalidad = new char[strlen(nac)+1];
    strcpy(nacionalidad, nac);
}

void ContratoMovil::setPrecioMinuto(float pM){
    precioMin = pM;
}

void ContratoMovil::setMinutosHablados(int mH){
    minHablados = mH;
}

float ContratoMovil::factura() const{

    float factura = precioMin * minHablados;

    return factura;
}

void ContratoMovil::ver(){

    cout << getDniContrato() << " (" << getIdContrato() << " - " << getFechaContrato() << ") ";
    cout << getMinutosHablados() << "m, " << getNacionalidad() << " " << getPrecioMinuto() << " - ";
    cout << factura() << "€";

}

ostream& operator<<(ostream &out, const ContratoMovil &cM){

    out << cM.getDniContrato() << " (" << cM.getIdContrato() << " - " << cM.getFechaContrato() << ") ";
    out << cM.getMinutosHablados() << "m, " << cM.getNacionalidad() << " " << cM.getPrecioMinuto() << " - ";
    out << cM.factura() << "€";

    return out;
}
