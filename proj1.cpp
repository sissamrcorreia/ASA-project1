// Projeto 1 - Analise de Sistemas de Algoritmos - 2023

// Grupo 2
// Cecilia Correia - 106827
// Luisa Fernandes - 102460


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Uma peça de placa
struct Piece {
    int width;
    int height;
    int price;
};

// Função para maximizar o valor que pode ser obtido a partir da chapa dada como entrada
int maximizeValue(int X, int Y, vector<Piece>& pieces) {
    vector<int> dp(X + 1, 0);

    for (const auto& piece : pieces) {
        if ((piece.width <= X && piece.height <= Y) || (piece.width <= Y && piece.height <= X)) {

        for (int i = piece.width; i <= X; ++i) {
            dp[i] = max(dp[i], dp[i - piece.width] + piece.price);

            // Verifica se é possível usar múltiplas cópias da mesma peça
            for (int k = 1; k * piece.height <= Y; ++k) {
                dp[i] = max(dp[i], dp[i - piece.width] + k * piece.price);
            }
        }

        // Considera a peça rodada
        if (piece.height >= X) {
            for (int i = piece.height; i <= X; ++i) {
                dp[i] = max(dp[i], dp[i - piece.height] + piece.price);

                for (int k = 1; k * piece.width <= Y; ++k) {
                    dp[i] = max(dp[i], dp[i - piece.height] + k * piece.price);
                }
            }
        }
        }
    }

    return dp[X];
}

int main() {
    int X, Y;
    std::cin >> X >> Y;

    int N;
    std::cin >> N;

    vector<Piece> pieces(N);
    for (int i = 0; i < N; ++i) {
        cin >> pieces[i].width >> pieces[i].height >> pieces[i].price;
    }

    int result = maximizeValue(X, Y, pieces);

    cout << result << endl;
    
    return 0;
}
