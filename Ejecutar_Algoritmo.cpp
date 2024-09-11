#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include <cstdlib>

#include "Quicksort.h"
#include "Mergesort.h"
#include "Selectsort.h"
#include "C++sort.h"

using namespace std;

vector<int> leerNumerosDesdeArchivo(const string& nombreArchivo) {
    vector<int> numeros;
    ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string numero;

            while (getline(ss, numero, ',')) { // Leer cada número separado por comas
                numeros.push_back(stoi(numero)); // Convertir la cadena a entero y añadir al vector
            }
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
    }

    return numeros;
}

void escribirNumerosEnArchivo(const string& nombreArchivo, const vector<int>& numeros) {
    ofstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        for (size_t i = 0; i < numeros.size(); i++) {
            archivo << numeros[i];
            if (i != numeros.size() - 1) {
                archivo << ","; // Separar los datos con comas
            }
        }
        archivo.close();
        cout << "Vector ordenado guardado en " << nombreArchivo << endl;
    } else {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
    }
}


int main() {
    system("python3 /home/chubi/Algoco/Tarea1/Generador_dataset.py");
    //Crea 3 vectores para asi ejecutar todos los algoritmos, si no el primero lo ordenaria y el segundo lo recibiria ordenado
    vector<int> datos1 = leerNumerosDesdeArchivo("dataset.txt");
    vector<int> datos2 = leerNumerosDesdeArchivo("dataset.txt");
    vector<int> datos3 = leerNumerosDesdeArchivo("dataset.txt");
    vector<int> datos4 = leerNumerosDesdeArchivo("dataset.txt");
    int n = datos1.size();

    auto inicio_select = chrono::high_resolution_clock::now();
    //======algoritmo======
    selectSort(datos1);
    //======algoritmo======
    auto fin_select = chrono::high_resolution_clock::now();
    chrono::duration<double> tiempo_select = fin_select - inicio_select;

    auto inicio_merge = chrono::high_resolution_clock::now();
    //======algoritmo======
    mergeSort(datos2, 0, n-1);
    //======algoritmo======
    auto fin_merge = chrono::high_resolution_clock::now();
    chrono::duration<double> tiempo_merge = fin_merge - inicio_merge;

    auto inicio_quick = chrono::high_resolution_clock::now();
    //======algoritmo======
    quickSort(datos3, 0, n-1);
    //======algoritmo======
    auto fin_quick = chrono::high_resolution_clock::now();
    chrono::duration<double> tiempo_quick = fin_quick - inicio_quick;

    auto inicio_intro = chrono::high_resolution_clock::now();
    //======algoritmo======
    /*En este caso transforma a un arreglo el vector ya que asi está implementada la funcion de sorting de c++ **/
    Introsort(&datos4[0], &datos4[0], &datos4[0] + n - 1); 
    //======algoritmo======
    auto fin_intro = chrono::high_resolution_clock::now();
    chrono::duration<double> tiempo_intro = fin_intro - inicio_intro;

    cout << "Tiempo de ejecucion de selectSort: " << tiempo_select.count() << endl;
    cout << "Tiempo de ejecucion de mergeSort: " << tiempo_merge.count() << endl;
    cout << "Tiempo de ejecucion de quickSort: " << tiempo_quick.count() << endl;
    cout << "Tiempo de ejecucion de introsort: " << tiempo_intro.count() << endl;

    escribirNumerosEnArchivo("dataset_output.txt", datos4);


    return 0;
}