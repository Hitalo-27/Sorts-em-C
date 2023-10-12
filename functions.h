#ifndef FUNCOES_H
#define FUNCOES_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <cstdlib>

#define TAM 1

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

#endif