#include <iostream>
#include "Usuario.h"

using namespace std;

int main() {
    Producto p1("Laptop", 1200.5, 5);
    Producto p2("Smartphone", 800.7, 10);
    Producto p3("Tablet", 450.0, 7);

    Usuario usuario("Juan Perez");
    CarritoCompras carrito;

    carrito.agregarProducto(p1,1);
    carrito.agregarProducto(p2,2);
    carrito.mostrarCarrito();

    carrito.eliminarProducto("Smartphone");
    carrito.mostrarCarrito();

    usuario.comprar(carrito);
    usuario.mostrarHistorialCompras();

    usuario.comprar(carrito);
    usuario.mostrarHistorialCompras();

    return 0;
}