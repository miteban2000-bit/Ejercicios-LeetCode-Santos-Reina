#ifndef itemCarrito_h
#define itemCarrito_h

#include "Producto.h"

class ItemCarrito {

private:
    Producto producto;
    int cantidad;

public:
    ItemCarrito(Producto producto, int cantidad): producto(producto), cantidad(cantidad) {}

    double getSubtotal() const { return producto.getPrecio() * cantidad; }
    int getCantidad() const { return cantidad; }
    string getNombreProducto() const { return producto.getNombre(); }

    void MostrarItem() const {
        cout << "Producto: " << producto.getNombre() 
             << ", Cantidad: " << cantidad 
             << ", Subtotal: $" << getSubtotal() << endl;
    }
};

#endif
