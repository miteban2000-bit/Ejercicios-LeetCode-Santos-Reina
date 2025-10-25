#ifndef Bicicleta_h
#define Bicicleta_h

#include "Vehiculo.h"

class Bicicleta : public Vehiculo {
  private:
    string tipo; // Ejemplo: Montaña, Urbana, Carretera

public:
    Bicicleta(string marca, string modelo, string placa, string tipo)
        : Vehiculo(marca, modelo, placa), tipo(tipo) {}

    void mostrarInfo() const override {
        Vehiculo::mostrarInfo();
        cout << "Marca [Bicicleta]: " << marca << endl;
        cout << "Modelo [Bicicleta]: " << modelo << endl;
        cout << "Placa [Bicicleta]: " << placa << endl;
        cout << "Tipo [Bicicleta]: " << tipo << endl;
        cout << "Disponible: " << (disponible ? "Sí" : "No") << endl;
    }
};
#endif /* Bicicleta_h */