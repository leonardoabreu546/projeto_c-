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
            cout << "Entrada inválida! Tente novamente: ";
        } else {
            return x;
        }
    }
}

int main() {
    int numeros[10];
    int estrelas[5];
    int opcao;

    srand(time(0));

    cout << "Bem-vindo ao Euro Milhões!\n\n";
   
    char escolha;
    
    while (true){
        
        cout << "Escolha S para aposta simples ou M para aposta múltipla: ";
        cin >> escolha;
        escolha = tolower(escolha);

        char tipo;
        cout << "Tipo de aposta - Manual (M) ou Automática (A)?\n";
        cin >> tipo;
        tipo = tolower(tipo);

        if (escolha == 's') {
            cout << "Aposta Simples selecionada.\n";

            // ================= APOSTA AUTOMÁTICA =================
            if (tipo == 'a') {

                for (int i = 0; i < 5; i++) {
                    int num;
                    bool repetido;

                    do {
                        num = rand() % 50 + 1;
                        repetido = false;

                        for (int j = 0; j < i; j++) {
                            if (numeros[j] == num) {
                                repetido = true;
                                break;
                            }
                        }
                    } while (repetido);

                    numeros[i] = num;
                }

                for (int i = 0; i < 2; i++) {
                    int est;
                    bool repetido;

                    do {
                        est = rand() % 12 + 1;
                        repetido = false;

                        for (int j = 0; j < i; j++) {
                            if (estrelas[j] == est) {
                                repetido = true;
                                break;
                            }
                        }
                    } while (repetido);

                    estrelas[i] = est;
                }
            }

            // ================= APOSTA MANUAL =================
            else {

                cout << "Introduza 5 números (1-50): ";
            
                for (int i = 0; i < 5; i++) {
                    do {

                        numeros[i] = lerInteiro();

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

                        estrelas[i] = lerInteiro();

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
            }

        } else if (escolha == 'm') {
            cout << "Aposta Múltipla selecionada.\n";

            if (tipo == 'a') {

                for (int i = 0; i < 5; i++) {
                    int num;
                    bool repetido;

                    do {
                        num = rand() % 50 + 1;
                        repetido = false;

                        for (int j = 0; j < i; j++) {
                            if (numeros[j] == num) {
                                repetido = true;
                                break;
                            }
                        }
                    } while (repetido);

                    numeros[i] = num;
                }

                for (int i = 0; i < 2; i++) {
                    int est;
                    bool repetido;

                    do {
                        est = rand() % 12 + 1;
                        repetido = false;

                        for (int j = 0; j < i; j++) {
                            if (estrelas[j] == est) {
                                repetido = true;
                                break;
                            }
                        }
                    } while (repetido);

                    estrelas[i] = est;
                }

            } else {

                cout << "Introduza 5 números (1-50): ";
                for (int i = 0; i < 5; i++) {
                    do {

                        numeros[i] = lerInteiro();

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
                        estrelas[i] = lerInteiro();

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