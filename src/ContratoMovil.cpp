#include "ContratoMovil.h"

ContratoMovil::ContratoMovil(long int dni, const Fecha &f, float pM, int mH): Contrato(dni, f){
    precioMin = pM;
    minHablados = mH;
}

ContratoMovil::~ContratoMovil()
{
    //dtor
}
