#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>

/**
 * @class Estudiante
 * @brief Representa la información académica básica de un estudiante.
 */
class Estudiante {
private:
    std::string nombre;
    int programa;
    float promedio;
    int creditosAprobados;

public:
    Estudiante(const std::string& nombre, int programa, float promedio, int creditosAprobados);

    void registrarNota(float nota, int creditos);
    void agregarCreditos(int creditos);
    std::string obtenerResumen() const;

    bool cumpleRequisitosGrado(int creditosRequeridos) const {
        return creditosAprobados >= creditosRequeridos;
    }

    float getPromedio() const { return promedio; }  ///< Getter para el promedio
};

#endif