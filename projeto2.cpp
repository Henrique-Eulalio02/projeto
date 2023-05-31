#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

// Função para embaralhar o vetor de cartas
void embaralhar(vector<int>& cartas) {
    srand(time(0));
    random_shuffle(cartas.begin(), cartas.end());
}

// Função para imprimir o tabuleiro com as cartas viradas
void imprimirTabuleiro(const vector<char>& tabuleiro) {
    for (const auto& carta : tabuleiro) {
        cout << carta << " ";
    }
    cout << endl;
}

int main() {
    // Vetor de cartas
    vector<int> cartas = { 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8 };

    // Embaralhar as cartas
    embaralhar(cartas);

    // Vetor para representar o tabuleiro
    vector<char> tabuleiro(cartas.size(), '*');

    // Variáveis de controle do jogo
    int primeiraEscolha = -1;
    int segundaEscolha = -1;
    int jogadas = 0;

    while (true) {
        // Imprimir o tabuleiro
        imprimirTabuleiro(tabuleiro);

        // Verificar se o jogador ganhou
        if (count(tabuleiro.begin(), tabuleiro.end(), '*') == 0) {
            cout << "Parabéns, você venceu em " << jogadas << " jogadas!" << endl;
            break;
        }

        // Obter a primeira escolha do jogador
        cout << "Escolha a primeira carta (digite o número de 0 a " << tabuleiro.size() - 1 << "): ";
        cin >> primeiraEscolha;

        // Verificar se a escolha é válida
        if (primeiraEscolha < 0 || primeiraEscolha >= tabuleiro.size() || tabuleiro[primeiraEscolha] != '*') {
            cout << "Escolha inválida. Tente novamente." << endl;
            continue;
        }

        // Virar a primeira carta
        tabuleiro[primeiraEscolha] = static_cast<char>(cartas[primeiraEscolha]);

        // Imprimir o tabuleiro com a primeira carta virada
        imprimirTabuleiro(tabuleiro);

        // Obter a segunda escolha do jogador
        cout << "Escolha a segunda carta (digite o número de 0 a " << tabuleiro.size() - 1 << "): ";
        cin >> segundaEscolha;

        // Verificar se a escolha é válida
        if (segundaEscolha < 0 || segundaEscolha >= tabuleiro.size() || tabuleiro[segundaEscolha] != '*') {
            cout << "Escolha inválida. Tente novamente." << endl;
            // Virar a primeira carta de volta
            tabuleiro[primeiraEscolha] = '*';
            continue;
        }

        // Virar a segunda carta
        tabuleiro[segundaEscolha] = static_cast<char>(cartas[segundaEscolha]);

        // Verificar se as cartas são iguais
        if (tabuleiro[primeiraEscolha] == tabuleiro[segundaEscolha]) {
            cout << "Parabéns, você encontrou um par!" << endl;
        }
        else {
            cout << "As cartas não são iguais." << endl;
            // Virar as cartas de volta
            tabuleiro[primeiraEscolha] = '*';
            tabuleiro[segundaEscolha] = '*';
        }

        // Incrementar o número de jogadas
        jogadas++;
    }

    return 0;
}
