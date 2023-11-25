// Projeto 1 - Analise de Sistemas de Algoritmos - 2023

// Grupo 2
// Cecilia Correia - 106827
// Luisa Fernandes - 102460


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Função para maximizar o valor que pode ser obtido a partir da chapa dada como entrada
int maximizeValue(int X, int Y, vector<vector<int>>& pieces) {
    vector<int> dp(X + 1, 0);

    for (const auto& piece : pieces) {
        int pieceWidth = piece[0];
        int pieceHeight = piece[1];
        int piecePrice = piece[2];

        if ((pieceWidth <= X && pieceHeight <= Y) || (pieceWidth <= Y && pieceHeight <= X)) {
            for (int i = pieceWidth; i <= X; i++) {
                dp[i] = max(dp[i], dp[i - pieceWidth] + piecePrice);

                // Verifica se é possível usar múltiplas cópias da mesma peça
                for (int k = 1; k * pieceHeight <= Y; k++) {
                    dp[i] = max(dp[i], dp[i - pieceWidth] + k * piecePrice);
                }
            }

            // Considera a peça rodada
            if (pieceHeight <= X) {
                for (int i = pieceHeight; i <= X; i++) {
                    for (int j = 1; j * pieceWidth <= Y; j++) {
                        dp[i] = max(dp[i], dp[i - pieceHeight] + j * piecePrice);
                    }
                }
            }
        }
    }

    return dp[X];
}

int main() {
    int X, Y;
    cin >> X >> Y;

    int N;
    cin >> N;

    vector<vector<int>> pieces(N, vector<int>(3));
    for (int i = 0; i < N; ++i) {
        cin >> pieces[i][0] >> pieces[i][1] >> pieces[i][2];
    }

    int result = maximizeValue(X, Y, pieces);

    cout << result << endl;

    return 0;
}