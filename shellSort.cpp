#include <iostream>
#include <vector>

#include "functions.h"

void shellSort(std::vector<int> &arr, int n) {
    // Define os intervalos iniciais
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Realiza uma classificação por intervalo
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            // Insire elementos corretamente na sublista com gap
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            // Coloca o elemento temporário na posição correta
            arr[j] = temp;
        }
    }
}

int main() {
    std::vector<int> arr = generateNumber();

    int n = arr.size();

    auto inicio = std::chrono::high_resolution_clock::now();

    shellSort(arr, n);

    auto fim = std::chrono::high_resolution_clock::now();

    auto tempo = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);

    std::cout << "O tempo necessario para ordenar todos os numeros foi de: " << tempo.count() << " milissegundos" << std::endl;

    return 0;
}
