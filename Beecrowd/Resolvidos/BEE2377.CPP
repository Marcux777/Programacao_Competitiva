#include <iostream>

using namespace std;

int main(){
	int l,d,k,p;
	int ped, soma = 0;
	cin >> l >> d;
	cin >> k >> p;
	ped = l/d;
	soma = (ped*p) + (k*l);
	cout << soma << endl;
}
