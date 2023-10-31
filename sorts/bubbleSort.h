#include "../functions/functions.h"

void bubble(std::vector<int>& vetor) {
    int troca = 0; // Variável para controlar se houve trocas durante a passagem
    int tamanho = vetor.size(); // Obtém o tamanho do vetor

    for (int i = 0; i < tamanho; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[i] > vetor[j]) { // Verifica se o elemento atual é maior que o próximo elemento
                std::swap(vetor[i], vetor[j]); // Realiza a troca dos elementos
                troca++; // Incrementa o contador de trocas
            }
        }
    }
}

SortResult runBubbleSort(std::vector<int>& vetorBubble) {
    auto inicioBubble = std::chrono::high_resolution_clock::now();
    bubble(vetorBubble);
    auto fimBubble = std::chrono::high_resolution_clock::now();
    long long tempoBubble = std::chrono::duration_cast<std::chrono::milliseconds>(fimBubble - inicioBubble).count();

    SortResult result;
    result.name = "Bubble Sort";
    result.sortedArray = vetorBubble;
    result.timeMillis = tempoBubble;

    return result;
}