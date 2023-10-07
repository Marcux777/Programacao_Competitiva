#include <bits/stdc++.h>

using namespace std;

int op(string s){
	if(s[0] == 'a' || s[1] == 'b' || s[2] == 'c'){ //pelo menos 1 tá no lugar
		return 1;
	}
	return 0;
}


int main(){
	int t;
	cin >> t;
	while(t--){
		string mat[11];
		
		for(int i = 0; i < 10; i++){
			cin >> mat[i];
		}
		long long int soma = 0;
		for(int i = 0; i < 10; i ++){
			for(int j = 0; j < 10; j++){
				if(mat[i][j] == 'X'){
					if(i == 0 || j == 0 || i == 9 || j == 9){
						soma += 1;
					}else{
						if(i == 1 || j == 1 || i == 8 || j == 8){
							soma += 2;
						}else{
							if(i == 2 || j == 2 || i == 7 || j == 7){
								soma += 3;
							}
							else{
								if(i == 3 || j == 3 || i == 6 || j == 6){
									soma += 4;
								}else{
									soma += 5;
								}
							}
						}
					}
				}
			}
		}
		cout << soma << endl;
	}
}