#include "young.h"



young::young(int linhas, int colunas)
{
	m = linhas;
	n = colunas;

	Y = new int*[linhas];
	for (int i = 0; i < linhas; ++i) {
		Y[i] = new int[colunas];
	}

	for (int i = 0; i < linhas; i++) {
		for (int j = 0; j < colunas; j++) {
			Y[i][j] = INT_MAX;
		}
	}
}

void young::youngify(int i, int j)
{
	int aux_i = i;
	int aux_j = j;

	if (i - 1 >= 0 && Y[i][j] < Y[i - 1][j])  {
		aux_i = i - 1;
		aux_j = j;
	}


	if (j - 1 >= 0 && Y[aux_i][aux_j] < Y[i][j - 1]) {
		aux_i = i;
		aux_j = j - 1;
	}
	
	if (i + 1 <= m-1 && Y[i][j] > Y[i + 1][j])  {
		aux_i = i + 1;
		aux_j = j;
	}


	if (j + 1 <= n-1 && Y[aux_i][aux_j] > Y[i][j + 1]) {
		aux_i = i;
		aux_j = j + 1;
	}

	if (aux_i != i || aux_j != j) {
		int aux = Y[i][j];
		Y[i][j] = Y[aux_i][aux_j];
		Y[aux_i][aux_j] = aux;
		youngify(aux_i, aux_j);
	}
}


bool young::vazio() {
	int aux = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (Y[i][j] == INT_MAX) {
				aux++;
			}
		}
	}
	if (aux >= (m*n) {
		return true;
	}
	else {
		return false;
	}
}

bool young::cheio() {
	int aux = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (Y[i][j] != INT_MAX) {
				aux++;
			}
		}
	}
	if (aux >= (m*n) {
		return true;
	}
	else {
		return false;
	}
}

bool young::remove(int &elem)
{
	if (!vazio()) {
		elem = Y[0][0];
		Y[0][0] = INT_MAX;
		youngify(0, 0);
		return true;
	}
	else {
		return false;
	}
}

bool young::insere(int valor)
{
	if (!cheio()) {
		Y[m-1][n-1] = valor;
		youngify(m-1, n-1);
		return true;
	}
	else {
		return false;
	}
}


young::~young()
{
	for (int i = 0; i <	m; ++i) {
		delete[] Y[i];
	}
	delete[] Y;
}

void young::imprime() {

	for (int j = 0; j < n; j++) {
		cout << "\t | ";
		for (int i = 0; i < m; i++) {

			if (Y[i][j] == INT_MAX)
			{
				cout << "~" << "  |  ";
			}
			else if (Y[i][j] < 10)
			{
				cout << Y[i][j] << "  |  ";
			}
			else if (Y[i][j] < 100) {
				cout << Y[i][j] << " |  ";
			}
			else {
				cout << Y[i][j] << "|  ";
			}
		}
		cout << endl << endl;
	}

}
