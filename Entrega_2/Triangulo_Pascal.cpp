#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> triangulo;

    for(int i=0; i<numRows;i++){
        vector<int>row(i+1,1);

        for(int j=1;j<i;j++){
            row[j]=triangulo[i-1][j-1]+triangulo[i-1][j];
        }
        triangulo.push_back(row);

    }
    return triangulo;
}

int main() {
    int numRows;
    cout << "Ingrese el numero de filas del triangulo de Pascal: ";
    cin >> numRows;

    vector<vector<int>> pascalTriangle = generate(numRows);

    cout << "Triangulo de Pascal con " << numRows << " filas:" << endl;
    for (const auto& row : pascalTriangle) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}