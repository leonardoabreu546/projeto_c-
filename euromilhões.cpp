#include <iostream>
#include <cstdlib>
#include <cctype>

using namespace std;

int main() {
    int numeros[10];
    int estrelas[5];
    int opcao;

    
    cout << "Bem-vindo ao Euro Milhões!\n\n";
   
    char escolha;
    
    while (true){
        
        cout << "Escolha S para aposta simples ou M para aposta múltipla: ";
        cin >> escolha;
        escolha = tolower(escolha);

        if (escolha == 's') {
            cout << "Aposta Simples selecionada.\n";
            cout << "Introduza 5 números (1-50): ";
            
            for (int i = 0; i < 5; i++) {
                do {
                    cin >> numeros[i];

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Entrada inválida! Digite um número: ";
                        numeros[i] = 0;
                        continue;
                    }

                    if (numeros[i] < 1 || numeros[i] > 50) {
                        cout << "Número inválido! Tente novamente: ";
                        continue;
                    }

                    bool repetido = false;

                    for (int j = 0; j < i; j++) {
                        if (numeros[i] == numeros[j]) {
                            cout << "Número repetido! Digite novamente: ";
                            repetido = true;
                            break;
                        }
                    }

                    if (repetido) {
                        numeros[i] = 0;
                    }

                } while (numeros[i] < 1 || numeros[i] > 50 || numeros[i] == 0);
            }
            
            cout << "Introduza 2 estrelas (1-12): ";
            for (int i = 0; i < 2; i++) {
                do {
                    cin >> estrelas[i];

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Entrada inválida! Digite um número: ";
                        estrelas[i] = 0;
                        continue;
                    }

                    if (estrelas[i] < 1 || estrelas[i] > 12) {
                        cout << "Estrela inválida! Tente novamente: ";
                        continue;
                    }

                    bool repetido = false;

                    for (int j = 0; j < i; j++) {
                        if (estrelas[i] == estrelas[j]) {
                            cout << "Estrela repetida! Digite novamente: ";
                            repetido = true;
                            break;
                        }
                    }

                    if (repetido) {
                        estrelas[i] = 0;
                    }

                } while (estrelas[i] < 1 || estrelas[i] > 12 || estrelas[i] == 0);
            }

        } else if (escolha == 'm') {
            cout << "Aposta Múltipla selecionada.\n";
            cout << "Introduza 5 números (1-50): ";
            for (int i = 0; i < 5; i++) {
                do {
                    cin >> numeros[i];

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Entrada inválida! Digite um número: ";
                        numeros[i] = 0;
                        continue;
                    }

                    if (numeros[i] < 1 || numeros[i] > 50) {
                        cout << "Número inválido! Tente novamente: ";
                        continue;
                    }

                    bool repetido = false;

                    for (int j = 0; j < i; j++) {
                        if (numeros[i] == numeros[j]) {
                            cout << "Número repetido! Digite novamente: ";
                            repetido = true;
                            break;
                        }
                    }

                    if (repetido) {
                        numeros[i] = 0;
                    }

                } while (numeros[i] < 1 || numeros[i] > 50 || numeros[i] == 0);
            }

            cout << "Introduza 2 estrelas (1-12): ";
            for (int i = 0; i < 2; i++) {
                do {
                    cin >> estrelas[i];

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Entrada inválida! Digite um número: ";
                        estrelas[i] = 0;
                        continue;
                    }

                    if (estrelas[i] < 1 || estrelas[i] > 12) {
                        cout << "Estrela inválida! Tente novamente: ";
                        continue;
                    }

                    bool repetido = false;

                    for (int j = 0; j < i; j++) {
                        if (estrelas[i] == estrelas[j]) {
                            cout << "Estrela repetida! Digite novamente: ";
                            repetido = true;
                            break;
                        }
                    }

                    if (repetido) {
                        estrelas[i] = 0;
                    }

                } while (estrelas[i] < 1 || estrelas[i] > 12 || estrelas[i] == 0);
            }

        } else {
            cout << "Opção inválida!\n";
            continue;
        }

        cout << "Numeros escolhidos: ";
        for (int i = 0; i < 5; i++) {
            cout << numeros[i] << " ";
        }

        cout << "\nEstrelas escolhidas: ";
        for (int i = 0; i < 2; i++) {
            cout << estrelas[i] << " ";
        }

        cout << "\nBoa sorte!\n";

        cout << "Deseja fazer outra aposta?\nContinuar-1 \n Sair-2 \n";
        cin >> opcao;

        if (opcao == 2) {
            cout << "Obrigado por jogar!\n";
            break;
        }
        
        else if (opcao != 1) {
            cout << "Opção inválida!\n";
        }
    }

    return 0;
}