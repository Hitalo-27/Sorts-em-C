#ifndef FUNCOES_H
#define FUNCOES_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <cstdlib>
#include <random>
#include <vector>

#define TAM 50000

using namespace std;

std::vector<int> readFile() {
    std::vector<int> numeros;

    std::ifstream arquivo("../numeros.txt");

    if (arquivo.is_open()) {
        int numero;
        char virgula;

        while (arquivo >> numero) {
            numeros.push_back(numero);

            if (arquivo >> virgula && virgula != ',') {
                std::cerr << "Erro na formatação do arquivo." << std::endl;
                return std::vector<int>();
            }
        }

        arquivo.close();
    } else {
        std::cerr << "Não foi possível abrir o arquivo." << std::endl;
        return std::vector<int>();
    }

    return numeros;
}

void fill(std::vector<int>& vetor) {
    std::vector<int> numerosDoArquivo = readFile();

    while (vetor.size() < TAM) {
        vetor.push_back(rand());
    }

    vetor.insert(vetor.end(), numerosDoArquivo.begin(), numerosDoArquivo.end());

}

void show(const std::vector<int>& vetor) {
    for (std::vector<int>::size_type i = 0; i < vetor.size(); i++) {
        std::cout << vetor[i] << "\t";
    }
    std::cout << std::endl;
}

std::vector<int> generateNumber() {
    std::random_device rd; // Semente aleatória do dispositivo
    std::mt19937 mt(rd());
    
    int min = 1; // número mínimo permitido na lista
    int max = 100000; // número máximo permitido na lista
    int num_elements = TAM; // Número de elementos na lista

    // Crie um vetor para armazenar os números aleatórios
    std::vector<int> random_numbers;

    // Crie uma distribuição uniforme
    std::uniform_int_distribution<int> dist(min, max);

    // Gere os números aleatórios e armazene-os no vetor
    for (int i = 0; i < num_elements; i++) {
        random_numbers.push_back(dist(mt));
    }

    return random_numbers;
}

#endif