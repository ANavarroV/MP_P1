#include <iostream>
#include "Fecha.h"

using namespace std;

Fecha::Fecha(int d, int m, int a){

    if(m < 1) m = 1;
    else if(m > 12) m = 12;

    mes = m;
    anio = a;

    int diaMAX = diasEnMes(m, a);
    if(d < 1) d = 1;
    else if(d > diaMAX) d = diaMAX;

    dia = d;

}

Fecha::~Fecha(){

}

int Fecha::getDia() const{

    return dia;
}

int Fecha::getMes() const{

    return mes;
}

int Fecha::getAnio() const{

    return anio;
}

void Fecha::setFecha(int d, int m, int a){

    Fecha f(d, m, a);
    *this = f;
}

bool Fecha::bisiesto() const{
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

int Fecha::diasEnMes(int m, int a) const{

    switch(m){

        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return this->bisiesto() ? 29 : 28;
        default:
            return 31;
    }
}

void Fecha::avanzarDia(){

    dia++;
    if(dia > diasEnMes(mes, anio)){
        dia = 1;
        mes++;
    }

    if(mes > 12){
        mes = 1;
        anio++;
    }

}

void Fecha::ver() const{

    if(dia < 10) cout << "0";
    cout << dia << "/";

    if(mes < 10) cout << "0";
    cout << mes << "/" << anio;
}

bool Fecha::operator==(const Fecha &f) const{

    bool iguales = false;
    if(this->dia == f.dia && this->mes == f.mes && this->anio == f.anio)
        iguales = true;

    return iguales;
}

ostream& operator<<(ostream &out, const Fecha &f){

    if(f.dia < 10) out << "0";
    out << f.dia << "/";

    if(f.mes < 10) out << "0";
    out << f.mes << "/" << f.anio;

    return out;
}

Fecha &Fecha::operator=(const Fecha &f){

    if(this != &f){
        dia = f.dia;
        mes = f.mes;
        anio = f.anio;
    }

    return *this;
}

Fecha Fecha::operator++(){ // ++f

    avanzarDia();

    return *this; //devolvemos el objeto fecha ya incrementado
}

Fecha Fecha::operator++(int flag){ // f++

    Fecha copia(*this);
    avanzarDia();

    return copia; //devolvemos el objeto fecha ya incrementado
}

Fecha Fecha::operator+(const int &i) const { // f + 4

    Fecha suma(dia, mes, anio); //creo fecha local suma igual a la que invoca el método
    for (int n=1; n<=i; n++)
        ++suma; //llamo al operator++ (notacion prefija) que ya tenemos hecha
    return suma; //devolvemos el objeto fecha suma ya incrementado
};

Fecha operator+(const int &i, const Fecha &f){ // 4 + f

    Fecha suma(f);
    for (int n = 1; n <= i; n++)
        ++suma; // usa tu operator++ prefijo
    return suma;
}
