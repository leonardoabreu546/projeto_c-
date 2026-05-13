#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>

using namespace std;

int lerInteiro() {
    int x;

    while (true) {
        cin >> x;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada invalida! Tente novamente: ";
        } else {
            return x;
        }
    }
}

bool numeroRepetido(int vetor[], int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == valor) {
            return true;
        }
    }

    return false;
}

void gerarAutomatico(int vetor[], int quantidade, int limite) {

    for (int i = 0; i < quantidade; i++) {
        int valor;

        do {
            valor = rand() % limite + 1;
        } while (numeroRepetido(vetor, i, valor));

        vetor[i] = valor;
    }
}

void lerManual(int vetor[], int quantidade, int min, int max, string mensagem) {

    cout << mensagem;

    for (int i = 0; i < quantidade; i++) {

        do {
            vetor[i] = lerInteiro();

            if (vetor[i] < min || vetor[i] > max) {
                cout << "Valor invalido! Tente novamente: ";
                continue;
            }

            if (numeroRepetido(vetor, i, vetor[i])) {
                cout << "Valor repetido! Digite novamente: ";
                vetor[i] = 0;
            }

        } while (vetor[i] < min || vetor[i] > max || vetor[i] == 0);
    }
}

void mostrarVetor(int vetor[], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        cout << vetor[i] << " ";
    }
}

int main() {

    int numeros[11];
    int estrelas[9];
    int opcao;

    int numerosm[5][11];
    int estrelasm[5][9];

    int numChaves = 0;
    int qtdNumeros = 0;
    int qtdEstrelas = 0;

    srand(time(0));

    cout << "Bem-vindo ao Euro Milhoes!\n\n";

    char escolha;

    while (true) {

        cout << "Escolha S para aposta simples ou M para aposta multipla: ";
        cin >> escolha;
        escolha = tolower(escolha);

        if (escolha != 's' && escolha != 'm') {
            cout << "Opcao invalida! Tente novamente.\n\n";
            continue;
        }

        char tipo;

        cout << "Tipo de aposta - Manual (M) ou Automatica (A)?\n";
        cin >> tipo;

        tipo = tolower(tipo);

        if (tipo != 'm' && tipo != 'a') {
            cout << "Opcao invalida! Tente novamente.\n";
            continue;
        }

        // ===================== APOSTA SIMPLES =====================
        if (escolha == 's') {

            cout << "Aposta Simples selecionada.\n";

            if (tipo == 'a') {

                gerarAutomatico(numeros, 5, 50);
                gerarAutomatico(estrelas, 2, 9);

            } else {

                lerManual(numeros, 5, 1, 50,
                    "Introduza 5 numeros (1-50): ");

                lerManual(estrelas, 2, 1, 9,
                    "Introduza 2 estrelas (1-9): ");
            }

            cout << "Numeros escolhidos: ";
            mostrarVetor(numeros, 5);

            cout << "\nEstrelas escolhidas: ";
            mostrarVetor(estrelas, 2);

            cout << "\n";
        }

        // ===================== APOSTA MULTIPLA =====================
        else if (escolha == 'm') {

            cout << "Aposta Multipla selecionada.\n";

            do {
                cout << "Quantas chaves pretende apostar? (1-5): ";
                numChaves = lerInteiro();
            } while (numChaves < 1 || numChaves > 5);

            do {
                cout << "Quantos numeros por chave? (5-11): ";
                qtdNumeros = lerInteiro();
            } while (qtdNumeros < 5 || qtdNumeros > 11);

            do {
                cout << "Quantas estrelas por chave? (2-9): ";
                qtdEstrelas = lerInteiro();
            } while (qtdEstrelas < 2 || qtdEstrelas > 9);

            // ====== INPUT DAS CHAVES ======
            for (int c = 0; c < numChaves; c++) {

                cout << "\nChave " << c + 1 << ":\n";

                if (tipo == 'a') {

                    gerarAutomatico(numerosm[c], qtdNumeros, 50);
                    gerarAutomatico(estrelasm[c], qtdEstrelas, 9);

                } else {

                    lerManual(numerosm[c], qtdNumeros, 1, 50,
                        "Numeros:\n");

                    lerManual(estrelasm[c], qtdEstrelas, 1, 9,
                        "Estrelas:\n");
                }
            }

            // ===================== RESUMO FINAL =====================
            cout << "\n========== RESUMO FINAL ==========\n";

            for (int c = 0; c < numChaves; c++) {

                cout << "\nChave " << c + 1 << ":\n";

                cout << "Numeros: ";
                mostrarVetor(numerosm[c], qtdNumeros);

                cout << "\nEstrelas: ";
                mostrarVetor(estrelasm[c], qtdEstrelas);

                cout << "\n";
            }
        }

        cout << "\nBoa sorte!\n";

        cout << "\nDeseja fazer outra aposta?\n";
        cout << "Continuar - 1\n";
        cout << "Sair - 2\n> ";

        cin >> opcao;

        if (opcao == 2) {
            cout << "Obrigado por jogar!\n";
            break;
        }
    }

    return 0;
}