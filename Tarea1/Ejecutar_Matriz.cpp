#include <iostream>
#include <vector>
#include <chrono>
#include "Generar_matrices.h"
#include "Cubico_tradicional.h"
#include "Cubico_optimizado.h"

using namespace std;

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
    cout << endl;
}


int main(){
    int u;
    cout << "dimension: "; 
    cin >> u;
    vector<vector<int>> A = genRandMatrix(u, 50);
    vector<vector<int>> B = genRandMatrix(50, u);
    vector<vector<int>> B_T = TransponerMatriz(B);

    auto inicio_trad = chrono::high_resolution_clock::now();
    //======algoritmo======
    vector<vector<int>>C = matrizTradicional(A, B);
    //======algoritmo======
    auto fin_trad = chrono::high_resolution_clock::now();
    chrono::duration<double> tiempo_trad = fin_trad - inicio_trad;

    auto inicio_trad_opt = chrono::high_resolution_clock::now();
    //======algoritmo======
    vector<vector<int>>D = matrizTradicional(A, B_T);
    //======algoritmo======
    auto fin_trad_opt = chrono::high_resolution_clock::now();
    chrono::duration<double> tiempo_trad_opt = fin_trad_opt - inicio_trad_opt;

    cout << "Tiempo de ejecucion algoritmo: " << tiempo_trad.count() << endl;
    cout << "Tiempo de ejecucion algoritmo optimizado: " << tiempo_trad_opt.count() << endl;
    return 0;
}
