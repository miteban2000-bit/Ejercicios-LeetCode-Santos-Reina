#include "Auto.h"
#include "Bicicleta.h"
#include "Sistema.h"
#include <limits>

void menu() {
    cout << "\n========== SISTEMA DE ALQUILER ==========\n";
    cout << "1. Registrar nuevo vehículo\n";
    cout << "2. Mostrar vehículos disponibles\n";
    cout << "3. Alquilar vehículo\n";
    cout << "4. Devolver vehículo\n";
    cout << "5. Salir\n";
    cout << "Seleccione una opción: ";
}

int main() {
    Sistema sistema;
    int opcion;

    do {
        menu();
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion) {
        case 1: {
            int tipo;
            cout << "\nSeleccione tipo de vehículo:\n";
            cout << "1. Auto\n";
            cout << "2. Bicicleta\n";
            cout << "Opción: ";
            cin >> tipo;
            cin.ignore();

            string marca, modelo, placa;
            cout << "Ingrese marca: ";
            getline(cin, marca);
            cout << "Ingrese modelo: ";
            getline(cin, modelo);
            cout << "Ingrese placa: ";
            getline(cin, placa);

            if (tipo == 1) {
                int capacidad;
                cout << "Ingrese capacidad de pasajeros: ";
                cin >> capacidad;
                cin.ignore();
                sistema.registroVeh(new Auto(marca, modelo, placa, capacidad));
            } else if (tipo == 2) {
                string tipoBici;
                cout << "Ingrese tipo de bicicleta (Montaña, Ruta, etc.): ";
                getline(cin, tipoBici);
                sistema.registroVeh(new Bicicleta(marca, modelo, placa, tipoBici));
            } else {
                cout << "Tipo inválido.\n";
            }
            break;
        }

        case 2:
            sistema.disponibles();
            break;

        case 3: {
            string placa;
            cout << "Ingrese la placa del vehículo a alquilar: ";
            getline(cin, placa);
            sistema.alquilar(placa);
            break;
        }

        case 4: {
            string placa;
            cout << "Ingrese la placa del vehículo a devolver: ";
            getline(cin, placa);
            sistema.devolucion(placa);
            break;
        }

        case 5:
            cout << "\n Saliendo del sistema...\n";
            break;

        default:
            cout << "Opción no válida.\n";
        }

    } while (opcion != 5);

    return 0;
}