#include <iostream>
using namespace std;

// Função para imprimir o tabuleiro
void imprimirTabuleiro(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << tabuleiro[i][j] << " ";
        }
        cout << endl;
    }
}

// Função para verificar se há um vencedor
bool verificarVencedor(char tabuleiro[3][3], char jogador) {
    // Verificar linhas
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) {
            return true;
        }
    }

    // Verificar colunas
    for (int j = 0; j < 3; j++) {
        if (tabuleiro[0][j] == jogador && tabuleiro[1][j] == jogador && tabuleiro[2][j] == jogador) {
            return true;
        }
    }

    // Verificar diagonais
    if ((tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) ||
        (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador)) {
        return true;
    }

    return false;
}

int main() {
    char tabuleiro[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char jogadorAtual = 'X';
    bool jogoFinalizado = false;

    while (!jogoFinalizado) {
        // Imprimir tabuleiro
        imprimirTabuleiro(tabuleiro);

        // Obter posição do jogador
        int linha, coluna;
        cout << "Jogador " << jogadorAtual << ", digite a linha (0-2): ";
        cin >> linha;
        cout << "Jogador " << jogadorAtual << ", digite a coluna (0-2): ";
        cin >> coluna;

        // Verificar se a posição é válida
        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabuleiro[linha][coluna] != ' ') {
            cout << "Posição inválida. Tente novamente." << endl;
            continue;
        }

        // Fazer a jogada
        tabuleiro[linha][coluna] = jogadorAtual;

        // Verificar se há um vencedor
        if (verificarVencedor(tabuleiro, jogadorAtual)) {
            cout << "Jogador " << jogadorAtual << " venceu!" << endl;
            jogoFinalizado = true;
        }

        // Verificar se houve empate
        bool tabuleiroCompleto = true;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tabuleiro[i][j] == ' ') {
                    tabuleiroCompleto = false;
                    break;
                }
            }
        }
        if (tabuleiroCompleto && !jogoFinalizado) {
            cout << "Empate!" << endl;
            jogoFinalizado = true;
        }

        // Alternar jogador
        jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
    }

    // Imprimir tabuleiro final
    imprimirTabuleiro(tabuleiro);

    cout << "ola" endl;

    return 0;
}
