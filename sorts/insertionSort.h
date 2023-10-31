#include "../functions/functions.h"

void insertion(std::vector<int>& vetor) {
    int tamanho = vetor.size(); // Obtem o tamanho do vetor

    for (int i = 1; i < tamanho; i++) {
        int chave = vetor[i]; // Seleciona o elemento atual como chave
        int j = i - 1; // Inicializa o índice j como o elemento anterior

        // Enquanto j for maior ou igual a 0 e o elemento em vetor[j] for maior do que a chave
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j]; // Move o elemento de vetor[j] para a direita
            j--; // Decrementa o índice j
        }

        vetor[j + 1] = chave; // Coloca a chave no local correto após a mudança
    }
}


SortResult runInsertionSort(std::vector<int>& vetorInsertion) {
    auto inicioInsertion = std::chrono::high_resolution_clock::now();
    insertion(vetorInsertion);
    auto fimInsertion = std::chrono::high_resolution_clock::now();
    long long tempoInsertion = std::chrono::duration_cast<std::chrono::milliseconds>(fimInsertion - inicioInsertion).count();

    SortResult result;
    result.name = "Insertion Sort";
    result.sortedArray = vetorInsertion;
    result.timeMillis = tempoInsertion;

    return result;
}