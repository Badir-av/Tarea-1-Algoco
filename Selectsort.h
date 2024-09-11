#include <iostream>
#include <vector>
#include <algorithm> // Para usar std::swap

using namespace std;

// Función para el ordenamiento por selección (Selection Sort)
void selectSort(vector<int>& arr)
{
    int n = arr.size(); // Obtener el tamaño del vector

    // Uno a uno, mueve el límite del subarreglo no ordenado
    for (int i = 0; i < n - 1; i++)
    {
        // Encuentra el elemento mínimo en la parte no ordenada
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Intercambia el elemento mínimo encontrado con el primer elemento
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}
