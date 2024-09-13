#include <iostream>
#include <locale.h>

using namespace std;

int main(){
	int dias, meses, anos, dias2;
	setlocale(LC_ALL, "portuguese");
	
	cin >> dias;
	anos = dias/365;
	cout << anos << " ano(s)" << endl;
	meses = (dias%365)/30;
	cout  << meses << " mes(es)" << endl;
	dias2 = (dias%365)%30;
	cout << dias2 << " dia(s)" << endl;
	
	return 0;
}
