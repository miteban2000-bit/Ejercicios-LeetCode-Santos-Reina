#ifndef Sistema_h
#define Sistema_h

#include <vector>
#include "Vehiculo.h"

class Sistema {
private:
    vector<Vehiculo*> vehiculos;

public:
    void registroVeh(Vehiculo* vehiculo) {
        vehiculos.push_back(vehiculo);
        cout << "Vehículo registrado exitosamente." << endl;
    }

    void disponibles()const{
        cout << "/n Vehículos disponibles:/n";
        bool hayDisponibles = false;
        for(auto v : vehiculos){
            if (v->estaDisponible()){
                v->mostrarInfo();
                hayDisponibles = true;
            }
        }
        if (!hayDisponibles) {
            cout << "No hay vehículos disponibles en este momento." << endl;

        }
    }

    void alquilar(const string& placa) {
        for(auto v : vehiculos) {
            if (v->getPlaca() == placa && v->estaDisponible()) {
                v->alquilar();
                cout << "Vehículo con placa " << placa << " alquilado exitosamente." << endl;
                return;
            }
        }
        cout << "Vehículo con placa " << placa << " no disponible para alquiler." << endl;
    }

    void devolucion(const string& placa){
        for (auto v : vehiculos) {
            if (v->getPlaca() == placa && !v->estaDisponible()) {
                v->devolver();
                cout << "Vehículo con placa " << placa << " devuelto exitosamente." << endl;
                return;
            }
        }
        cout << "Vehículo con placa " << placa << " no se encuentra alquilado." << endl;
    }

    ~Sistema() {
        for (auto v : vehiculos) {
            delete v;
        }
    }
};

#endif /* Sistema_h */