#include "../functions/functions.h"

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

SortResult runShellSort(std::vector<int>& vetorShell) {
    int n = vetorShell.size();
    auto inicioShell = std::chrono::high_resolution_clock::now();
    shellSort(vetorShell, n);
    auto fimShell = std::chrono::high_resolution_clock::now();
    long long tempoShell = std::chrono::duration_cast<std::chrono::milliseconds>(fimShell - inicioShell).count();

    SortResult result;
    result.name = "Shell Sort";
    result.sortedArray = vetorShell;
    result.timeMillis = tempoShell;

    return result;
}
