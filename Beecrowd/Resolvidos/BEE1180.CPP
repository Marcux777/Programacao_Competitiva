#include <iostream>

using namespace std;

int main(){
	int N, i, j, X[1000];
	int menor;
	cin >> N;
	menor = 100000;
	for (i = 0; i < N; i++){
		cin >> X[i];
		if (X[i] < menor){
			menor = X[i];
			j = i;
		}
	}
	cout << "Menor valor: " << menor << endl;
	cout << "Posicao: " << j << endl;
}