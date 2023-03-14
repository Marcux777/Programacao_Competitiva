#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int i,p = 0;
	float soma, media, x;
	
	soma = 0;
	
	for(i = 1; i <= 6; i++){
		cin >> x;
		
		if (x > 0){
			p++;
			soma = soma + x;
		}
	}
	media = soma/p;
	cout << p << " valores positivos" << endl;
	cout << setprecision(2);
	cout << media << endl;
}