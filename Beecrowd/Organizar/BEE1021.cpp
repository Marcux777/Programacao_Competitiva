#include <iostream>

using namespace std;

int main(){
	double n,nota;
	int moeda;
	cin >> n;
	//NOTAS
	cout << "NOTAS:\n";
	nota = int(n)/100;
	cout << nota <<" nota(s) de R$ 100.00" << endl;
	nota = int(n)%100/50;
	cout << nota <<" nota(s) de R$ 50.00" << endl;
	nota = int(n)%100%50/20;
	cout << nota <<" nota(s) de R$ 20.00" << endl;
	nota = int(n)%100%50%20/10;
	cout << nota <<" nota(s) de R$ 10.00" << endl;
	nota = int(n)%100%50%20%10/5;
	cout << nota <<" nota(s) de R$ 5.00" << endl;
	nota = int(n)%100%50%20%10%5/2;
	cout << nota <<" nota(s) de R$ 2.00" << endl;
	//MOEDA
	moeda = n*100;
	cout << "MOEDAS:\n";
	nota = moeda%10000%5000%2000%1000%500%200/100;
	cout << nota <<" moeda(s) de R$ 1.00" << endl;
	nota = moeda%10000%5000%2000%1000%500%200%100/50;
	cout << nota <<" moeda(s) de R$ 0.50" << endl;
	nota = moeda%10000%5000%2000%1000%500%200%100%50/25;
	cout << nota <<" moeda(s) de R$ 0.25" << endl;
	nota = moeda%10000%5000%2000%1000%500%200%100%50%25/10;
	cout << nota <<" moeda(s) de R$ 0.10" << endl;
	nota = moeda%10000%5000%2000%1000%500%200%100%50%25%10/5;
	cout << nota <<" moeda(s) de R$ 0.05" << endl;
	nota = moeda%10000%5000%2000%1000%500%200%100%50%25%10%5;
	cout << nota <<" moeda(s) de R$ 0.01" << endl;
	return 0;
}