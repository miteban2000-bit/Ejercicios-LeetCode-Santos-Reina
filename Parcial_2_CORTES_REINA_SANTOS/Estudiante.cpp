#include "Estudiante.h"
#include <sstream>
#include <iomanip>

Estudiante::Estudiante(const std::string& nombre, int programa, float promedio, int creditosAprobados)
    : nombre(nombre), programa(programa), promedio(promedio), creditosAprobados(creditosAprobados) {}


void Estudiante::registrarNota(float nota, int creditos) {
    float totalPuntos = promedio * creditosAprobados + nota * creditos;
    creditosAprobados += creditos;
    promedio = totalPuntos / creditosAprobados;
}


void Estudiante::agregarCreditos(int creditos) {
    creditosAprobados += creditos;
}


std::string Estudiante::obtenerResumen() const {
    std::ostringstream resumen;
    resumen << std::fixed << std::setprecision(2);
    resumen << "Nombre: " << nombre << "\n";
    resumen << "Programa: " << programa << "\n";
    resumen << "Promedio: " << promedio << "\n";
    resumen << "Créditos aprobados: " << creditosAprobados << "\n";
    return resumen.str();
}