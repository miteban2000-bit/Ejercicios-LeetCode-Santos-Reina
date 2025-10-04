#include <iostream>
using namespace std;

bool isPalindrome(int x) {
    // Los negativos no son palíndromos
    if (x < 0) return false;

    long reves = 0;
    int normal = x;

    // Invertir el número
    while (x > 0) {
        int digit = x % 10;          
        reves = reves * 10 + digit;
        x /= 10;                     
    }

    // Si el número normal es igual al reves es palíndromo
    return normal == reves;
}

int main() {
    int x;
    cout << "Ingrese un numero entero: ";
    cin >> x;

    if (isPalindrome(x)) {
        cout << "Verdadero el numero " << x << " es palindromo" << endl;
    } else {
        cout << "Falso el numero " << x << " no es palindromo" << endl;
    }

    return 0;
}