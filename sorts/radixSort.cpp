#include "../functions/functions.h"

// Função para encontrar o maior elemento em um vetor
int encontrarMaiorElemento(const std::vector<int>& vetor) {
    int maior = vetor[0]; // Inicializa com o primeiro elemento do vetor
    for (int elemento : vetor) {
        if (elemento > maior) { // Verifica se o elemento atual é maior que o maior encontrado até agora
            maior = elemento; // Se sim, atualiza o valor de 'maior'
        }
    }
    return maior;
}

// Função para realizar a ordenação por contagem para um dígito específico
void ordenacaoPorContagem(std::vector<int>& vetor, int exp) {
    int tamanho = vetor.size();
    std::vector<int> saida(tamanho); // Cria um vetor auxiliar 'saida' com o mesmo tamanho do vetor original
    const int base = 10; // Define a base, geralmente 10 para dígitos decimais
    std::vector<int> contador(base, 0); // Cria um vetor 'contador' para contar ocorrências de cada dígito

    for (int i = 0; i < tamanho; i++) {
        contador[(vetor[i] / exp) % base]++; // Calcula as contagens com base no dígito atual
    }

    for (int i = 1; i < base; i++) {
        contador[i] += contador[i - 1]; // Acumula as contagens
    }

    for (int i = tamanho - 1; i >= 0; i--) {
        saida[contador[(vetor[i] / exp) % base] - 1] = vetor[i]; // Reorganiza os elementos no vetor 'saida'
        contador[(vetor[i] / exp) % base]--; // Atualiza as contagens
    }

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = saida[i]; // Copia os elementos ordenados de volta para o vetor original
    }
}

void radix(std::vector<int>& vetor) {
    int maior = encontrarMaiorElemento(vetor);

    for (int exp = 1; maior / exp > 0; exp *= 10) {
        ordenacaoPorContagem(vetor, exp);
    }
}

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    std::vector<int> vetor;
    srand(static_cast<unsigned>(time(nullptr)));

    fill(vetor);

    auto inicio = std::chrono::high_resolution_clock::now();

    radix(vetor);

    auto fim = std::chrono::high_resolution_clock::now();
    auto tempo = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);

    std::cout << "O tempo necessario para ordenar todos os numeros foi de: " << tempo.count() << " milissegundos" << std::endl;

    system("pause");

    show(vetor);

    return 0;
}