#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Função para maximizar o valor que pode ser obtido a partir da chapa dada como entrada
int maximizeValue(int X, int Y, vector<vector<int>>& pieces) {
    // Tabela bidimensional para programação dinâmica
    vector<vector<int>> dp(X + 1, vector<int>(Y + 1, 0));

    for (const auto& piece : pieces) {
        int pieceWidth = piece[0];
        int pieceHeight = piece[1];
        int piecePrice = piece[2];

        if ((pieceWidth <= X && pieceHeight <= Y) || (pieceWidth <= Y && pieceHeight <= X)) {
            for (int i = pieceWidth; i <= X; i++) {
                dp[i][0] = max(dp[i][0], dp[i - pieceWidth][0] + piecePrice);

                // Verifica se é possível usar múltiplas cópias da mesma peça
                for (int k = 1; k * pieceHeight <= Y; k++) {
                    dp[i][k * pieceHeight] = max(dp[i][k * pieceHeight], dp[i - pieceWidth][k * pieceHeight] + k * piecePrice);
                }
            }

            // Considera a peça rodada
            if (pieceHeight <= X) {
                for (int i = pieceHeight; i <= X; i++) {
                    for (int j = pieceWidth; j <= Y; j++) {
                        dp[i][j] = max(dp[i][j], dp[i - pieceHeight][j - pieceWidth] + piecePrice);
                    }
                }
            }
        }
    }

    return dp[X][Y];
}

int main() {
    int X, Y;
    scanf("%d %d", &X, &Y);

    int N;
    scanf("%d", &N);

    vector<vector<int>> pieces(N, vector<int>(3));
    for (int i = 0; i < N; ++i) {
        scanf("%d %d %d", &pieces[i][0], &pieces[i][1], &pieces[i][2]);
    }

    int result = maximizeValue(X, Y, pieces);

    printf("%d\n", result);

    return 0;
}