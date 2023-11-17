// Projeto 1 - Analise de Sistemas de Algoritmos - 2023

// Grupo 2
// Cecilia Correia - 106827
// Luisa Fernandes - 102460


#include <iostream>
#include <vector>
#include <algorithm>
//#include <stdio.h>
//#include <string.h>
using namespace std;

// void print valor máximo que pode ser obtido a partir da chapa dada como input

// void cleanupMemory() { delete[] pieces;}

//uma peça de placa
struct Piece {
    int width;
    int height;
    int price;
};

int maximizeValue(int X, int Y, vector<Piece>& pieces) {
    vector<int> dp(X + 1, 0);

    for (const auto& piece : pieces) {
        for (int i = piece.width; i <= X; ++i) {
            dp[i] = max(dp[i], dp[i - piece.width] + piece.price);

            // Verifica se é possível usar múltiplas cópias da mesma peça
            for (int k = 1; k * piece.height <= Y; ++k) {
                dp[i] = max(dp[i], dp[i - piece.width] + k * piece.price);
            }
        }
    }

    return dp[X];
}

int main() {
    // ler dimensoes da placa
    int X, Y;
    std::cin >> X >> Y;

    // ler numero de tipos de pecas
    int N;
    std::cin >> N;

    /* criar um vetor para armazenar as pecas
    std::vector<int> pieces(N);

    for (int i = 0; i < N; ++i) {
        int ai, bi, pi;
        std::cin >> ai >> bi >> pi;

    }*/
    vector<Piece> pieces(N);
    for (int i = 0; i < N; ++i) {
        cin >> pieces[i].width >> pieces[i].height >> pieces[i].price;
    }

    int result = maximizeValue(X, Y, pieces);

    cout << result << endl;
    
    return 0;
}