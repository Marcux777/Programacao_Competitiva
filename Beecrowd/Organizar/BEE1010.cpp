#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int A1, A2, B1, B2;
	double valor1, valor2;
	
	cout << fixed << setprecision(2);
	cin >> A1 >> B1 >> valor1;
	cin >> A2 >> B2 >> valor2;
		
	cout << fixed << setprecision(2);
	cout << "VALOR A PAGAR: R$ " << (B1*valor1) + (B2*valor2) << endl;
	
	return 0;
}