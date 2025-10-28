#include "ContratoTP.h"

float ContratoTP::precioTP = 10.0;
int ContratoTP::limiteMinutos = 300;

ContratoTP::ContratoTP(long int dni, const Fecha &f, int mH): Contrato(dni, f){
    minHablados = mH;
}

ContratoTP::~ContratoTP(){
    //dtor
}

int ContratoTP::getLimiteMinutos(){
    return limiteMinutos;
}

float ContratoTP::getPrecio(){
    return precioTP;
}

int ContratoTP::getMinutosHablados() const{

    return minHablados;
}

float ContratoTP::factura() const{

    float factura;
    int excesoMin;

    if(minHablados > limiteMinutos)
        excesoMin = minHablados - limiteMinutos;

    factura = precioTP + (excesoMin * 0.15);

    return factura;
}

void ContratoTP::setTarifaPlana(int m, float p){

    limiteMinutos = m;
    precioTP = p;
}

void ContratoTP::setMinutosHablados(int mH){
    minHablados = mH;
}

void ContratoTP::ver(){

    cout << getDniContrato() << " (" << getIdContrato() << " - " << getFechaContrato() << ") ";
    cout << getMinutosHablados() << "m, " << getLimiteMinutos() << "(" << getPrecio() << ")";
    cout << " - " << factura() << "€";

}

ostream& operator<<(ostream &out, ContratoTP &cTP){

    out << cTP.getDniContrato() << " (" << cTP.getIdContrato() << " - " << cTP.getFechaContrato() << ") ";
    out << cTP.getMinutosHablados() << "m, " << cTP.getLimiteMinutos() << "(" << cTP.getPrecio() << ")";
    out << " - " << cTP.factura() << "€";

    return out;
}
