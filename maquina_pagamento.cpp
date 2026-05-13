#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath> // Adicionado para usar a função floor

using namespace std;

int gerarValor() {
    return rand() % 991 + 10;
}

bool notaValida(int nota) {
    return nota == 5   ||
           nota == 10  ||
           nota == 20  ||
           nota == 50  ||
           nota == 100 ||
           nota == 200 ||
           nota == 500;
}

void mostrarFalta(int valor, int pago) {
    float falta = (valor - pago) / 100.0;
    cout << "Falta pagar: " << falta << " euros\n";
}

int main() {
    srand(time(0));
    int valor = gerarValor();
    int pago = 0;
    
    double entrada; 
    int nota;

    cout << "CAIXA DE PAGAMENTO\n";
    cout << "Valor a pagar: " << valor / 100.0 << " euros\n\n";

    while (pago < valor) {
        cout << "Introduza nota (5, 10, 20, 50, 100, 200, 500): ";
        
        if (!(cin >> entrada)) { 
            cout << "Entrada invalida!\n";
            cin.clear();
            cin.ignore(1000, '\n');
            mostrarFalta(valor, pago);
            continue;
        }

        // --- BLOCO DE CÊNTIMOS ---
        // floor() ajuda a garantir que pegamos a parte inteira correta
        nota = (int)floor(entrada); 
        double centimos = entrada - nota;

        // Se houver mais de 0.001 de cêntimos, devolve
        if (centimos > 0.001) { 
            cout << "A maquina nao aceita moedas.\n";
            // fixed e precision ajudariam aqui, mas mantive simples:
            cout << centimos << " euros devolvidos.\n";
        }
        // -------------------------

        if (notaValida(nota)) {
            pago += nota * 100;
            if (pago < valor) {
                mostrarFalta(valor, pago);
            }
        } else {
            cout << "Nota invalida!\n";
            mostrarFalta(valor, pago);
        }
    }

    int troco = pago - valor;
    cout << "\nTroco: " << troco / 100.0 << " euros\n";

    return 0;
}