#include <iostream>
#include "young.h"

using namespace std;

int main() {
	young y(2, 2);
	int i = -1;
	while (i != 0) {
		cout << "Selecione uma opcao" << endl;
		cout << "1. Insere elemento no Quadro de Young." << endl;
		cout << "2. Remove menor elemento do Quadro de Young." << endl;
		cout << "3. Imprime elementos do Quadro de Young." << endl;
		cout << "0. Sair." << endl;
		cin >> i;

		if (i == 1) {
			if (y.cheio()) {
				cout << "O Quadro de Young esta cheio" << endl;
			} else {
				cout << "Digite um numero inteiro" << endl;
				int aux;
				cin >> aux;
				y.insere(aux);
			}
		} else if (i == 2) {
			int elem;
			if (y.vazio()) {
				cout << "O Quadro de Young esta vazio" << endl;
			} else {
				y.remove(elem);
				cout << "Elemento " << elem << " removido" << endl;
			}

		} else if (i == 3) {
			y.imprime();
		}
	}

}