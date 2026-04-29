#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Gerar valor aleatório
    srand(time(0));
    int valor = rand() % 991 + 10; 
    
    int pago = 0;
    int nota;

    cout << "CAIXA DE PAGAMENTO\n";
    cout << "Valor a pagar: " << valor / 100.0 << " euros\n\n";

    // Ciclo para pedir as notas
    while (pago < valor) {
        cout << "Introduza nota (5, 10, 20, 50, 100, 200, 500): ";
        cin >> nota;

        float falta; 

        // Validação simples
        if (nota == 5 || nota == 10 || nota == 20 || nota == 50 || nota == 100 || nota == 200 || nota == 500) {
            pago += (nota * 100);
            
            if (pago < valor) {
                falta = (valor - pago) / 100.0;
                cout << "Faltam pagar " << falta << " euros.\n";
            }
        } else {
            cout << "Nota invalida ou entrada incorreta!\n";
            
            falta = (valor - pago) / 100.0;
            cout << "Falta pagar: " << falta << " euros\n"; 
            
            cin.clear(); 
            cin.ignore(1000, '\n'); 
        }
    }

    // Calcular troco final
    int troco = pago - valor;
    cout << "\nTroco: " << troco / 100.0 << " euros\n";

    return 0;
}