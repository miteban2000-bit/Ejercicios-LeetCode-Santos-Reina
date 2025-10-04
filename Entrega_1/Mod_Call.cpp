#include <iostream>
#include <string>
#include <cstdlib>
#include <functional>

using namespace std;

// Funciones para operaciones
float sumar(float a, float b) {
    return a + b;
}

float restar(float a, float b) {
    return a - b;
}

float multiplicar(float a, float b) {
    return a * b;
}

float dividir(float a, float b) {
    if (b == 0) {
        throw invalid_argument("Error: División por cero.");
    }
    return a / b;
}

// Función que recibe un callback
float operar(float a, float b, function<float(float, float)> operacion) {
    return operacion(a, b);
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Uso incorrecto. Formato: <operando1> <operador> <operando2>\n";
        return 1;
    }

    try {
        // Convertir argumentos
        float num1 = stof(argv[1]);
        string operador = argv[2];
        float num2 = stof(argv[3]);

        // Selección de operación
        function<float(float, float)> operacion;

        if (operador == "+") {
            operacion = sumar;
        } else if (operador == "-") {
            operacion = restar;
        } else if (operador == "*" || operador == "x" || operador == "X") {
            operacion = multiplicar;
        } else if (operador == "/") {
            operacion = dividir;
        } else {
            cerr << "Operador no válido. Usa +, -, *, x o /.\n";
            return 1;
        }

        float resultado = operar(num1, num2, operacion);
        cout << "Resultado: " << resultado << endl;

    } catch (invalid_argument& e) {
        cerr << "Error: Argumento no válido. Asegúrate de ingresar números válidos.\n";
        return 1;
    } catch (exception& e) {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}