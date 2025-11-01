#ifndef Producto_h
#define Producto_h

#include <string>
#include <iostream>

using namespace std;

class Producto{

private:
    string nombre;
    double precio;
    int stock;

public:
    Producto(string nombre, double precio, int stock): nombre(nombre), precio(precio), stock(stock) {};

    string getNombre() const{return nombre;}
    double getPrecio() const{return precio;}
    int getStock() const{return stock;}

    void reducirStock(int cantidad){
        if(cantidad <= stock){
            stock -= cantidad;
        } else {
            cerr << "Error: No hay suficiente stock para reducir." << endl;
        }
    }
    
    void aumentarStock(int cantidad){stock+= cantidad;}

};

#endif
