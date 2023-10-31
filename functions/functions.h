#ifndef FUNCOES_H
#define FUNCOES_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <cstdlib>
#include <random>
#include <ctime>
#include <map>

#define TAM 50000

using namespace std;

struct SortResult {
    std::string name;
    std::vector<int> sortedArray;
    long long timeMillis;
};

int fillInFile() {
    // Abra o arquivo para escrita, isso apagará o conteúdo existente
    std::ofstream arquivo("numeros.txt");

    // Verifique se o arquivo foi aberto com sucesso
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return 1;
    }

    // Inicialize o gerador de números aleatórios
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Gere e escreva 500 números aleatórios separados por vírgula no arquivo
    for (int i = 0; i < 500; ++i) {
        int numero = std::rand() % 1000;  // Gere números aleatórios de 0 a 999 (você pode ajustar o intervalo conforme necessário)
        arquivo << numero;

        // Adicione uma vírgula a menos no último número
        if (i < 499) {
            arquivo << ",";
        }
    }

    // Feche o arquivo
    arquivo.close();

    return 0;
}

std::vector<int> readFile() {
    std::vector<int> numeros;

    std::ifstream arquivo("numeros.txt");

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
    fillInFile();
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