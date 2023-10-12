#include "functions.h"

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

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    std::vector<int> vetor;
    srand(static_cast<unsigned>(time(nullptr)));

    fill(vetor);

    auto inicio = std::chrono::high_resolution_clock::now();

    bubble(vetor);

    auto fim = std::chrono::high_resolution_clock::now();
    auto tempo = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);

    std::cout << "O tempo necessario para ordenar todos os numeros foi de: " << tempo.count() << " milissegundos" << std::endl;

    system("pause");

    show(vetor);

    return 0;
}
