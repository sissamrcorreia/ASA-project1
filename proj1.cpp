// Projeto 1 - Analise de Sistemas de Algoritmos - 2023

// Grupo 2
// Cecilia Correia - 106827
// Luisa Fernandes - 102460


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Função para maximizar o valor que pode ser obtido a partir da chapa dada como entrada
int maximizeValue(int X, int Y, vector<vector<int>>& dp2) {
    for (int i = 1; i <= X; i++) {
        for (int j = 1; j <= Y; j++) {
            // Caso 1: Não cortar a chapa
            dp2[i][j] = max(dp2[i][j], dp2[i - 1][j]);

            // Caso 2: Não cortar a chapa
            dp2[i][j] = max(dp2[i][j], dp2[i][j - 1]);

            // Caso 3: Cortar a chapa horizontalmente
            for (int k = 0; k < i; k++) {
                dp2[i][j] = max(dp2[i][j], dp2[k][j] + dp2[i - k][j]);
            }

            // Caso 4: Cortar a chapa verticalmente
            for (int k = 0; k < j; k++) {
                dp2[i][j] = max(dp2[i][j], dp2[i][k] + dp2[i][j - k]);
            }
        }
    }

    return dp2[X][Y];
}

int main() {
    int X, Y;
    scanf("%d %d", &X, &Y);

    int N;
    scanf("%d", &N);

    // Criar uma matriz representando a chapa grande e inicializar com zeros
    vector<vector<int>> dp2(X + 1, vector<int>(Y + 1, 0));

    // Preencher a matriz com os preços das peças
    for (int i = 0; i < N; ++i) {
        int pieceWidth, pieceHeight, piecePrice;
        scanf("%d %d %d", &pieceWidth, &pieceHeight, &piecePrice);

        if ((pieceWidth <= X && pieceHeight <= Y)) {
            // Se a peça cabe na chapa, preencher as posições correspondentes com o preço
            dp2[pieceWidth][pieceHeight] = piecePrice;
        }
        // Peça rodada
        if ((pieceWidth <= Y && pieceHeight <= X)) {
            dp2[pieceHeight][pieceWidth] = piecePrice;
        }
    }

    int result = maximizeValue(X, Y, dp2);

    printf("%d\n", result);

    return 0;
}