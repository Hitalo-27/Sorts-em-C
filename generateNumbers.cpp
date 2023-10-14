#include <iostream>
#include <random>
#include <vector>

std::vector<int> generateNumber() {
    std::random_device rd; // Semente aleatória do dispositivo
    std::mt19937 mt(rd());
    
    int min = 1;
    int max = 100;
    int num_elements = 50; // Número de elementos na lista

    // Crie um vetor para armazenar os números aleatórios
    std::vector<int> random_numbers;

    // Crie uma distribuição uniforme
    std::uniform_int_distribution<int> dist(min, max);

    // Gere os números aleatórios e armazene-os no vetor
    for (int i = 0; i < num_elements; i++) {
        random_numbers.push_back(dist(mt));
    }

    // Imprima a lista de números aleatórios
    // std::cout << "Números aleatórios: ";
    // for (int num : random_numbers) {
    //     std::cout << num << " ";
    // }
    // std::cout << std::endl;

    return random_numbers;
}
