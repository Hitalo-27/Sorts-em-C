#include "functions.h"

void counting(std::vector<int>& vetor) {
    int tamanho = vetor.size();

    // Encontrar o valor máximo no vetor
    int max = vetor[0];
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > max) {
            max = vetor[i];
        }
    }

    // Crie um vetor auxiliar para contar as ocorrências de cada elemento
    std::vector<int> contador(max + 1, 0);

    // Preencha o vetor contador com a contagem de elementos
    for (int i = 0; i < tamanho; i++) {
        contador[vetor[i]]++;
    }

    // Reconstruir o vetor ordenado a partir do vetor contador
    int i = 0;
    for (int j = 0; j <= max; j++) {
        while (contador[j] > 0) {
            vetor[i] = j;
            i++;
            contador[j]--;
        }
    }
}

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    std::vector<int> vetor;
    srand(static_cast<unsigned>(time(nullptr)));

    fill(vetor);

    auto inicio = std::chrono::high_resolution_clock::now();

    counting(vetor);

    auto fim = std::chrono::high_resolution_clock::now();
    auto tempo = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);

    std::cout << "O tempo necessario para ordenar todos os numeros foi de: " << tempo.count() << " milissegundos" << std::endl;

    system("pause");

    show(vetor);

    return 0;
}