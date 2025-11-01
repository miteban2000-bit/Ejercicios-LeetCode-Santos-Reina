#ifndef Usuario_h
#define Usuario_h

#include <string>
#include <vector>
#include "CarritoCompras.h"
using namespace std;

class Usuario {

private:
    string nombreUsuario;
    vector<vector<Producto>> historialCompras;

public:
    Usuario(string nombreUsuario) : nombreUsuario(nombreUsuario) {}

    void comprar(CarritoCompras& carrito) {
        vector<Producto> productosComprados = carrito.getProductos();
        if (productosComprados.empty()) {
            cout << "El carrito está vacío. No se realizó ninguna compra." << endl;
            return;

        }
        historialCompras.push_back(productosComprados);
        cout << "Compra realizada por el usuario: " << nombreUsuario << endl;

    }

    void mostrarHistorialCompras() const {
        cout << "Historial de compras del usuario: " << nombreUsuario << endl;
        if (historialCompras.empty()) {
            cout << "No hay compras realizadas." << endl;
            return;
        }
        int compraNumero = 1;
        for (const auto& compra : historialCompras) {
            cout << "Compra #" << compraNumero++ << ":" << endl;
            for (const auto& producto : compra) {
                cout << "Producto comprado" << endl;
            
            }

        }
    }
};

#endif
