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

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    std::vector<int> vetor;
    srand(static_cast<unsigned>(time(nullptr)));

    fill(vetor);

    int n = vetor.size();

    auto inicio = std::chrono::high_resolution_clock::now();

    quickSort(vetor, 0, n - 1);

    auto fim = std::chrono::high_resolution_clock::now();
    auto tempo = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);

    std::cout << "O tempo necessario para ordenar todos os numeros foi de: " << tempo.count() << " milissegundos" << std::endl;

    system("pause");

    show(vetor);

    return 0;
}

