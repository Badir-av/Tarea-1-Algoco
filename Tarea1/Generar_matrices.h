#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;

vector<vector<int>> genRandMatrix(int filas, int columnas) {
    vector<vector<int>> matrix(filas, vector<int>(columnas));
    
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matrix[i][j] = rand() % 100; // Números aleatorios de 0 a 9
        }
    }

    return matrix;
}
