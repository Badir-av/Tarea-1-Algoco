#include<vector>

using namespace std;

vector<vector<int>> TransponerMatriz(const vector<vector<int>>& B) {
    int filas = B.size();
    int columnas = B[0].size();
    // Crear una matriz transpuesta con dimensiones intercambiadas
    vector<vector<int>> B_T(columnas, vector<int>(filas));
    
    // Realiza la transposición
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            B_T[j][i] = B[i][j];
        }
    }
    return B_T;
}

vector<vector<int>> matrizTradicionalOptimizado(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size(); // Suponiendo matrices n x n
    vector<vector<int>> B_T = TransponerMatriz(B); // Obtener la matriz transpuesta
    vector<vector<int>> resultado(n, vector<int>(n, 0));   // Inicializar la matriz de resultado con ceros

    // Multiplicación de matrices usando la matriz transpuesta
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                resultado[i][j] += A[i][k] * B_T[j][k];
            }
        }
    }

    return resultado;
}
