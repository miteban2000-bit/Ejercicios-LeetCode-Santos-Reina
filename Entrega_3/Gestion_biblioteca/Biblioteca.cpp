#ifndef LIBRO_H
#define LIBRO_H
#include <string>

class Book {
    std::string t, a, i;
    bool disponible;
public:
    Book(const std::string &t, const std::string &a, const std::string &i) : t(t), a(a), i(i), disponible(true) {}
    std::string getTitulo() const { return t; }
    std::string getAutor() const { return a; }
    std::string getISBN() const { return i; }
    bool estaDisponible() const { return disponible; }
    void setDisponible(bool d) { disponible = d; }
};

#endif // LIBRO_H

// include/Biblio.h
#ifndef BIBLIOTECA_H    
#define BIBLIOTECA_H
#include <vector>
#include "libro.h"

class Biblio {
    std::vector<Book> libros;
public:
    void agregarBook(const Book &l) { libros.push_back(l); }
    void eliminarBook(const std::string &i);
    void mostrarBooksDisponibles() const;
    Book* buscarBookPorTitulo(const std::string &t);
};

#endif // BIBLIOTECA_H

// src/Book.cpp #include "Book.h"

Book::Book(const std::string &t, const std::string &a, const std::string &i) : t(t), a(a), i(i), disponible(true) {}

std::string Book::getTitulo() const { return t; } std::string Book::getAutor() const { return a; } std::string Book::getISBN() const { return i; } bool Book::estaDisponible() const { return disponible; } void Book::setDisponible(bool estado) { disponible = estado; }

// src/Biblio.cpp #include "Biblio.h" #include <iostream>

void Biblio::agregarBook(const Book &libro) { libros.push_back(libro); }

void Biblio::eliminarBook(const std::string &i) { for (auto it = libros.begin(); it != libros.end(); ++it) { if (it->getISBN() == i) { libros.erase(it); std::cout << "Book eliminado. "; return; } } std::cout << "Book no encontrado. "; }std::cout << "Book no encontrado.\n"; }

void Biblio::mostrarBooksDisponibles() const { for (const auto &l : libros) if (l.estaDisponible()) std::cout << "Titulo: " << l.getTitulo() << ", Autor: " << l.getAutor() << ", ISBN: " << l.getISBN() << " "; } }

Book* Biblio::buscarBookPorTitulo(const std::string &t) { for (auto &l : libros) if (l.getTitulo() == t) return &l; return nullptr; } }

// src/main.cpp #include "Biblio.h" #include <iostream>

int main() { Biblio b; b.agregarBook(Book("El Principito", "Antoine de Saint-Exupéry", "123456")); b.agregarBook(Book("Cien Años de Soledad", "Gabriel García Márquez", "789101")); std::cout << "Books disponibles: "; b.mostrarBooksDisponibles(); std::string t; std::cout << " Buscar libro por título: "; std::getline(std::cin, t); if (auto *l = b.buscarBookPorTitulo(t)) { std::cout << "Book encontrado: " << l->getTitulo() << " "; l->setDisponible(false); } else std::cout << "Book no encontrado. "; std::cout << " Books disponibles después de préstamo: "; b.mostrarBooksDisponibles(); return 0; }// CMakeLists.txt cmake_minimum_required(VERSION 3.10) project(Biblio)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(Biblio src/main.cpp src/Book.cpp src/Biblio.cpp)