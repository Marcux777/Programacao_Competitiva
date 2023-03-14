#include <iostream>

using namespace std;

int main(){
	int i, num;
	int par = 0,impar = 0,positivo = 0,negativo = 0;
	
	
	for (i = 0; i < 5; i++){
		cin >> num;
		if (num % 2 == 0){
			par++;
			
		} else {
			impar++;
		}
		if(num > 0){
			positivo++;
		} else{
			if(num < 0){
				negativo++;

			}
		}
	}
	cout << par << " valor(es) par(es)" << endl;
	cout << impar << " valor(es) impar(es)" << endl;
	cout << positivo << " valor(es) positivo(s)" << endl;
	cout << negativo << " valor(es) negativo(s)" << endl;
	
	return 0;
}