#ifndef Vehiculo_h
#define Vehiculo_h

#include <iostream>
#include <string>
using namespace std;

class Vehiculo {
protected:
    string marca;
    string modelo;
    string placa;
    bool disponible;

public:
    Vehiculo(string marca, string modelo, string placa)
        : marca(marca), modelo(modelo), placa(placa), disponible(true) {}

    virtual void mostrarInfo() const {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Placa: " << placa << endl;
        cout << "Disponible: " << (disponible ? "Sí" : "No") << endl;
    }

    string getPlaca() const {
        return placa;
    }   
    bool estaDisponible() const {
        return disponible;
    }
    void alquilar() {
        disponible = false;
    }
    void devolver() {
        disponible = true;
    }
};
#endif /* Vehiculo_h */