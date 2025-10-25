#ifndef Auto_h
#define Auto_h

#include "Vehiculo.h"

class Auto : public Vehiculo {
   private:
    int cantidadPasajeros;

   public:
    Auto(string marca, string modelo, string placa, int cantidadPasajeros)
        : Vehiculo(marca, modelo, placa), cantidadPasajeros(cantidadPasajeros) {}

    void mostrarInfo() const override {
        cout << "Marca de auto: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Placa: " << placa << endl;
        cout << "Cantidad de pasajeros: " << cantidadPasajeros << endl;
        cout << "Disponible: " << (disponible ? "Sí" : "No") << endl;
    }
};

#endif /* Auto_h */
