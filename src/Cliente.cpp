#include "Cliente.h"

Cliente::Cliente(long int d, const char nom[], const Fecha &f): fechaAlta(f){
    dni = d;
    nombre = new char[strlen(nom)+1];
    strcpy(nombre, nom);
}

Cliente::Cliente(const Cliente &otro): fechaAlta(otro.fechaAlta){
    dni = otro.dni;
    nombre = new char[strlen(otro.nombre) + 1];
    strcpy(nombre, otro.nombre);
}

Cliente::~Cliente(){
    delete [] nombre;
}

long int Cliente::getDni() const{
    return this->dni;
}

char* Cliente::getNombre() const{
    return this->nombre;
}

Fecha Cliente::getFecha() const{
    return this->fechaAlta;
}

void Cliente::setNombre(char nom[]){
    nombre = new char[strlen(nom)+1];
    strcpy(nombre, nom);
}

void Cliente::setFecha(Fecha f){
    fechaAlta.setFecha(f.getDia(), f.getMes(), f.getAnio());
}

ostream& operator<<(ostream &out, const Cliente &c){

    out << c.getNombre() << " (" << c.getDni() << " - " << c.getFecha() << ")";
    return out;
}

void Cliente::ver() const{
    cout << getNombre() << " (" << getDni() << " - " << getFecha() << ")";
}

Cliente& Cliente::operator=(const Cliente &otro) {
    if (this != &otro) {
        delete[] nombre;  // libero la memoria previa
        dni = otro.dni;
        fechaAlta = otro.fechaAlta;

        nombre = new char[strlen(otro.nombre) + 1];
        strcpy(nombre, otro.nombre);
    }
    return *this;
}

bool Cliente::operator==(const Cliente &otro) const{

    bool iguales = false;

    if(this->dni == otro.dni && strcmp(this->nombre, otro.nombre) == 0 && this->fechaAlta == otro.fechaAlta)
        iguales = true;

    return iguales;
}
