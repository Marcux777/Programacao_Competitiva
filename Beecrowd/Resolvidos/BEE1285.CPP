#include <bits/stdc++.h>
using namespace std;

bool verifica(int n){
	stringstream ss;
	ss << n;
	string str = ss.str();
	for(int i = 0; i < str.size()-1; i++){
		for(int j = i+1; j < str.size(); j++){
			if(str[i] == str[j]){
				return false;
			}
		}
	}
	return true;
}

int main(){
	int n, m, cont;
	while(cin >> n >> m){
		cont = 0;
		for(int i = n; i <= m; i++){
			if(verifica(i)){
				cont++;
			}
		}
		cout << cont << endl;
	}
}
