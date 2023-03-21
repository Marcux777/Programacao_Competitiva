#include <bits/stdc++.h>
using namespace std;
int main(){
	int v1[6], v2[6], cont = 0;
	for(int i = 0; i < 6; i++){
		cin >> v1[i];
	}
	for(int i = 0; i < 6; i++){
		cin >> v2[i];
	}
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			if(v1[i] == v2[j]){
				cont++;
			}
		}
	}
	if(cont == 3){
		cout << "terno" << endl;
	}else{
		if(cont == 4){
			cout << "quadra" << endl;
		}else{
			if(cont == 5){
				cout << "quina" << endl;
			}else{
				if(cont == 6){
					cout << "sena" << endl;
				}else{
					cout << "azar" << endl;
				}
			}
		}
	}
}
