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

int main() {
    int numeros[11];  // aumentado para suportar aposta multipla (max 11)
    int estrelas[9];  // aumentado para suportar aposta multipla (max 9)
    int opcao;

    srand(time(0));

    cout << "Bem-vindo ao Euro Milhoes!\n\n";
   
    char escolha;
    
    while (true){
        
        cout << "Escolha S para aposta simples ou M para aposta multipla: ";
        cin >> escolha;
        escolha = tolower(escolha);

        if (escolha == 's') {
            cout << "Aposta Simples selecionada.\n";

            char tipo;
            cout << "Tipo de aposta - Manual (M) ou Automatica (A)?\n";
            cin >> tipo;
            tipo = tolower(tipo);

            // ================= APOSTA AUTOMATICA =================
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
                        est = rand() % 9 + 1;
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

                cout << "Introduza 5 numeros (1-50): ";
            
                for (int i = 0; i < 5; i++) {
                    do {

                        numeros[i] = lerInteiro();

                        if (numeros[i] < 1 || numeros[i] > 50) {
                            cout << "Numero invalido! Tente novamente: ";
                            continue;
                        }

                        bool repetido = false;

                        for (int j = 0; j < i; j++) {
                            if (numeros[i] == numeros[j]) {
                                cout << "Numero repetido! Digite novamente: ";
                                repetido = true;
                                break;
                            }
                        }

                        if (repetido) {
                            numeros[i] = 0;
                        }

                    } while (numeros[i] < 1 || numeros[i] > 50 || numeros[i] == 0);
                }
                
                cout << "Introduza 2 estrelas (1-9): ";
                for (int i = 0; i < 2; i++) {
                    do {

                        estrelas[i] = lerInteiro();

                        if (estrelas[i] < 1 || estrelas[i] > 9) {
                            cout << "Estrela invalida! Tente novamente: ";
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

                    } while (estrelas[i] < 1 || estrelas[i] > 9 || estrelas[i] == 0);
                }
            }

            cout << "Numeros escolhidos: ";
            for (int i = 0; i < 5; i++) {
                cout << numeros[i] << " ";
            }

            cout << "\nEstrelas escolhidas: ";
            for (int i = 0; i < 2; i++) {
                cout << estrelas[i] << " ";
            }
            cout << "\n";

        } else if (escolha == 'm') {
            cout << "Aposta Multipla selecionada.\n";

            // ====== Perguntar quantas chaves (1-5) ======
            int numChaves;
            cout << "Quantas chaves pretende apostar? (1-5): ";
            do {
                numChaves = lerInteiro();
                if (numChaves < 1 || numChaves > 5) {
                    cout << "Numero de chaves invalido! Introduza entre 1 e 5: ";
                }
            } while (numChaves < 1 || numChaves > 5);

            // ====== Perguntar quantos numeros por chave (5-11) ======
            int qtdNumeros;
            cout << "Quantos numeros por chave? (5-11): ";
            do {
                qtdNumeros = lerInteiro();
                if (qtdNumeros < 5 || qtdNumeros > 11) {
                    cout << "Quantidade invalida! Introduza entre 5 e 11: ";
                }
            } while (qtdNumeros < 5 || qtdNumeros > 11);

            // ====== Perguntar quantas estrelas por chave (2-9) ======
            int qtdEstrelas;
            cout << "Quantas estrelas por chave? (2-9): ";
            do {
                qtdEstrelas = lerInteiro();
                if (qtdEstrelas < 2 || qtdEstrelas > 9) {
                    cout << "Quantidade invalida! Introduza entre 2 e 9: ";
                }
            } while (qtdEstrelas < 2 || qtdEstrelas > 9);

            char tipo;
            cout << "Tipo de aposta - Manual (M) ou Automatica (A)?\n";
            cin >> tipo;
            tipo = tolower(tipo);

            // ====== Loop por cada chave ======
            for (int c = 1; c <= numChaves; c++) {
                cout << "\n--- Chave " << c << " ---\n";

                // ================= APOSTA AUTOMATICA =================
                if (tipo == 'a') {

                    for (int i = 0; i < qtdNumeros; i++) {
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

                    for (int i = 0; i < qtdEstrelas; i++) {
                        int est;
                        bool repetido;

                        do {
                            est = rand() % 9 + 1;
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

                    cout << "Introduza " << qtdNumeros << " numeros (1-50): ";
                    for (int i = 0; i < qtdNumeros; i++) {
                        do {

                            numeros[i] = lerInteiro();

                            if (numeros[i] < 1 || numeros[i] > 50) {
                                cout << "Numero invalido! Tente novamente: ";
                                continue;
                            }

                            bool repetido = false;

                            for (int j = 0; j < i; j++) {
                                if (numeros[i] == numeros[j]) {
                                    cout << "Numero repetido! Digite novamente: ";
                                    repetido = true;
                                    break;
                                }
                            }

                            if (repetido) {
                                numeros[i] = 0;
                            }

                        } while (numeros[i] < 1 || numeros[i] > 50 || numeros[i] == 0);
                    }

                    cout << "Introduza " << qtdEstrelas << " estrelas (1-9): ";
                    for (int i = 0; i < qtdEstrelas; i++) {
                        do {
                            estrelas[i] = lerInteiro();

                            if (estrelas[i] < 1 || estrelas[i] > 9) {
                                cout << "Estrela invalida! Tente novamente: ";
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

                        } while (estrelas[i] < 1 || estrelas[i] > 9 || estrelas[i] == 0);
                    }
                }

                cout << "Numeros escolhidos: ";
                for (int i = 0; i < qtdNumeros; i++) {
                    cout << numeros[i] << " ";
                }

                cout << "\nEstrelas escolhidas: ";
                for (int i = 0; i < qtdEstrelas; i++) {
                    cout << estrelas[i] << " ";
                }
                cout << "\n";
            }

        } else {
            cout << "Opcao invalida!\n";
            continue;
        }

        cout << "\nBoa sorte!\n";

        cout << "Deseja fazer outra aposta?\nContinuar-1 \n Sair-2 \n";
        cin >> opcao;

        if (opcao == 2) {
            cout << "Obrigado por jogar!\n";
            break;
        }
        
        else if (opcao != 1) {
            cout << "Opcao invalida!\n";
        }
    }

    return 0;
}