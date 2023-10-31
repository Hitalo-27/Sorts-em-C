#include "../functions/functions.h"

// Função para dividir o array em torno do pivô
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Escolhe o elemento mais à direita como pivô
    int i = (low - 1); // Índice do menor elemento

    for (int j = low; j <= high - 1; j++) {
        // Se o elemento atual for menor ou igual ao pivô
        if (arr[j] <= pivot) {
            i++; // Incrementa o índice do menor elemento
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Função principal do Quick Sort
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // Encontre o índice do pivô, elemento no lugar correto
        int pi = partition(arr, low, high);

        // Ordena os elementos separadamente antes e depois do pivô
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

SortResult runQuickSort(std::vector<int>& vetorQuick) {
    int n = vetorQuick.size();
    auto inicioQuick = std::chrono::high_resolution_clock::now();
    quickSort(vetorQuick, 0, n - 1);
    auto fimQuick = std::chrono::high_resolution_clock::now();
    long long tempoQuick = std::chrono::duration_cast<std::chrono::milliseconds>(fimQuick - inicioQuick).count();

    SortResult result;
    result.name = "Quick Sort";
    result.sortedArray = vetorQuick;
    result.timeMillis = tempoQuick;

    return result;
}
