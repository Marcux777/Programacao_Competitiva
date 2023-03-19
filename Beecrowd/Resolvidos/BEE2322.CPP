#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, pos;
	cin >> n;
	bool v[n+1];
	for(int i = 1; i <= n; i++){
		v[i] = false;
	}
	for(int i = 1; i < n; i++){
		int aux;
		cin >> aux;
		v[aux] = true;
	}
	for(int i = 1; i <= n; i++){
		if(!v[i]){
			pos = i;
		}
	}
	cout << pos << endl;
}
