#include "../functions/functions.h"

void selection(std::vector<int>& vetor) {
    int tamanho = vetor.size(); 

    for (int i = 0; i < tamanho - 1; i++) {
        int indiceMenor = i; // Assume que o elemento atual é o menor
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[indiceMenor]) { // Verifica se encontrou um elemento menor
                indiceMenor = j; // Atualiza o índice do menor elemento encontrado
            }
        }
        if (indiceMenor != i) { // Se o menor elemento não for o próprio elemento atual
            std::swap(vetor[i], vetor[indiceMenor]); // Troca o elemento atual com o menor elemento encontrado
        }
    }
}

SortResult runSelectionSort(std::vector<int>& vetorSelection) {
    auto inicioSelection = std::chrono::high_resolution_clock::now();
    selection(vetorSelection);
    auto fimSelection = std::chrono::high_resolution_clock::now();
    long long tempoSelection = std::chrono::duration_cast<std::chrono::milliseconds>(fimSelection - inicioSelection).count();

    SortResult result;
    result.name = "Selection Sort";
    result.sortedArray = vetorSelection;
    result.timeMillis = tempoSelection;

    return result;
}