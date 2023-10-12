#include "functions.h"

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

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    std::vector<int> vetor;
    srand(static_cast<unsigned>(time(nullptr)));

    fill(vetor);

    auto inicio = std::chrono::high_resolution_clock::now();

    selection(vetor);

    auto fim = std::chrono::high_resolution_clock::now();
    auto tempo = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);

    std::cout << "O tempo necessario para ordenar todos os numeros foi de: " << tempo.count() << " milissegundos" << std::endl;

    system("pause");

    show(vetor);

    return 0;
}