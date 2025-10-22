#ifndef FECHA_H
#define FECHA_H

#include <iostream>

using namespace std;

class Fecha {

    int dia, mes, anio;

    public:
        Fecha(int d, int m, int a);
        virtual ~Fecha();

        int getDia() const;
        int getMes() const;
        int getAnio() const;

        void setFecha(int d, int m, int a);

        // Un año es bisiesto si es divisible por 4 y no es divisible por 100 a menos que sea divisible por 400
        bool bisiesto() const;
        int diasEnMes(int m, int a) const;
        void avanzarDia();

        void ver() const;

        bool operator==(const Fecha &f) const;
        Fecha &operator=(const Fecha &f);

        Fecha operator++();
        Fecha operator++(int flag);
        Fecha operator+(const int &i) const; //f+5

        friend Fecha operator+(const int &i, const Fecha &f);
        friend ostream& operator<<(ostream &out, const Fecha &f);
};

Fecha operator+(const int &i, const Fecha &f); //const por seguridad y & por velocidad

#endif // FECHA_H
