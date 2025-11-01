#include <iostream>
#include <vector>
#include "Estudiante.h"

int main() {
    std::vector<Estudiante> estudiantes;

    // Crear varios estudiantes
    estudiantes.emplace_back("Juan Pérez", 101, 4.0f, 30);
    estudiantes.emplace_back("María López", 102, 3.8f, 40);
    estudiantes.emplace_back("Carlos Gómez", 103, 4.2f, 25);

    // Simular registro de nuevas notas
    estudiantes[0].registrarNota(3.5f, 3);
    estudiantes[1].registrarNota(4.0f, 4);
    estudiantes[2].registrarNota(4.8f, 2);

    // Agregar créditos aprobados
    estudiantes[0].agregarCreditos(5);
    estudiantes[1].agregarCreditos(3);
    estudiantes[2].agregarCreditos(6);

    // Mostrar resumen de cada estudiante
    std::cout << "===== RESUMEN GENERAL DE ESTUDIANTES =====\n";
    for (const auto& est : estudiantes) {
        std::cout << est.obtenerResumen() << std::endl;
        std::cout << "------------------------------------------\n";
    }

    // Calcular promedio general del grupo
    float sumaPromedios = 0;
    for (const auto& est : estudiantes) {
        sumaPromedios += est.getPromedio();
    }

    float promedioGeneral = sumaPromedios / estudiantes.size();
    std::cout << "Promedio general del grupo: " << promedioGeneral << std::endl;

    return 0;
}