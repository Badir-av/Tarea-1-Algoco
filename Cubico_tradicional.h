#include <vector>
#include<iostream>

using namespace std;

vector<vector<int>> matrizTradicional(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();    // Número de filas de A
    int m = A[0].size(); // Número de columnas de A (o filas de B)
    int p = B[0].size(); // Número de columnas de B

    // Crea la matriz de resultado con dimensiones n x p, inicializada en 0
    vector<vector<int>> resultado(n, vector<int>(p, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < m; ++k) {
                resultado[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return resultado;
}