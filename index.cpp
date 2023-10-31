#include "sorts/selectionSort.h"
#include "sorts/insertionSort.h"
#include "sorts/bubbleSort.h"

int main() {
    std::cout << "Executando.... " << std::endl;

    std::vector<int> vetor;

    fill(vetor);

    // Crie cópias do vetor para cada algoritmo
    std::vector<int> vetorSelection = vetor;
    std::vector<int> vetorInsertion = vetor;
    std::vector<int> vetorBubble = vetor;

    // Execute os algoritmos de ordenação e registre o tempo
    SortResult selectionResult = runSelectionSort(vetorSelection);
    SortResult insertionResult = runInsertionSort(vetorInsertion);
    SortResult bubbleResult = runBubbleSort(vetorBubble);

    // Encontre o algoritmo mais rápido
    SortResult fastestResult = selectionResult;
    if (insertionResult.timeMillis < fastestResult.timeMillis) {
        fastestResult = insertionResult;
    }
    if (bubbleResult.timeMillis < fastestResult.timeMillis) {
        fastestResult = bubbleResult;
    }

    // Exiba os resultados do algoritmo mais rápido
    std::cout << "Algoritmo mais rápido: " << fastestResult.name << std::endl;
    std::cout << "Tempo de ordenação: " << fastestResult.timeMillis << " milissegundos" << std::endl;

    system("pause");

    std::cout << "Array ordenado: ";
    for (int num : fastestResult.sortedArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}