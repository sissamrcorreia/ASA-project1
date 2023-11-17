// Projeto 1 - Analise de Sistemas de Algoritmos - 2023

// Grupo 2
// Cecilia Correia - 106827
// Luisa - 10


#include <iostream>
#include <vector>
//#include <stdio.h>
//#include <string.h>

// void print valor máximo que pode ser obtido a partir da chapa dada como input

// void cleanupMemory() { delete[] pieces;}


int main() {
    // ler dimensoes da placa
    int X, Y;
    std::cin >> X >> Y;

    // ler numero de tipos de pecas
    int N;
    std::cin >> N;

    // criar um vetor para armazenar as pecas
    std::vector<int> pieces(N);

    for (int i = 0; i < N; ++i) {
        int ai, bi, pi;
        std::cin >> ai >> bi >> pi;

    }
    
    return 0;
}