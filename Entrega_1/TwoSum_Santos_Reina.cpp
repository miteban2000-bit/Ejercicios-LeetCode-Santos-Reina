#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t, objetivo;
    
    // Tamaño del arreglo
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> t;

    vector<int> nums(t);

    // Elementos del arreglo
    cout << "Ingrese los " << t << " numeros del arreglo:" << endl;
    for (int i = 0; i < t; i++) {
        cin >> nums[i];
    }

    // Valor objetivo
    cout << "Ingrese el valor objetivo: ";
    cin >> objetivo;

    // Búsqueda de dos números que sumen el valor objetivo
    for (int i = 0; i < t; i++) {
        for (int j = i + 1; j < t; j++) {
            if (nums[i] + nums[j] == objetivo) {
                cout << "Los indices son: [" << i << ", " << j << "]" << endl;
                return 0;
            }
        }
    }

    cout << "No se encontraron dos numeros que sumen " << objetivo << endl;
    return 0;
}
