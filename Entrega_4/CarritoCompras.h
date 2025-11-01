#ifndef CarritoCompras_h
#define CarritoCompras_h

#include <vector>
#include <string>
#include <iostream>
#include "Producto.h"
using namespace std;

class CarritoCompras {

private:
    vector<Producto> productos;

public:
    void agregarProducto(const Producto& p, int cantidad) {
        if(cantidad > p.getStock()){
            cerr << "Error: No hay suficiente stock para agregar el producto al carrito." << endl;
            return;
        }
        for(int i = 0; i < cantidad; ++i) {
            productos.push_back(p);
        }
        cout << "Producto agregado al carrito: " << p.getNombre() << " (Cantidad: " << cantidad << ")" << endl;
    }

    void eliminarProducto(const string& nombre) {
        for(size_t i = 0; i < productos.size(); ++i) {
            if(productos[i].getNombre() == nombre) {
                productos.erase(productos.begin() + i);
                cout << "Producto eliminado del carrito: " << nombre << endl;
                return;
            }
        }
        cerr << "Error: Producto no encontrado en el carrito." << endl;
    }

    double calcularTotal() const {
        double total = 0.0;
        for(const auto& producto : productos) {
            total += producto.getPrecio();
        }
        return total;
    }

    void mostrarCarrito() const {
        cout << "Productos en el carrito:" << endl;
        if(productos.empty()) {
            cout << "El carrito está vacío." << endl;
            return;
        }
        for(const auto& producto : productos) {
            cout << producto.getNombre() << " - $" << producto.getPrecio() << " (Stock: " << producto.getStock() << ")" << endl;
        }
        cout << "Total: $" << calcularTotal() << endl;
    }

    vector<Producto> getProductos() const {
        return productos;
    }
};

#endif
