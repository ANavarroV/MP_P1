#include "ContratoTP.h"

float ContratoTP::precioTP = 10.0;

ContratoTP::ContratoTP(long int dni, const Fecha &f, int mH): Contrato(dni, f){
    minHablados = mH;
}

ContratoTP::~ContratoTP(){
    //dtor
}

int ContratoTP::getLimiteMinutos(){
    return minHablados;
}

static float ContratoTP::getPrecio(){
    return precioTP;
}
