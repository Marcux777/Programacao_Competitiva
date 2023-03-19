#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, r, i;
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	while(cin >> n >> r){
		bool v[n+1];
		int cont = 0;
		memset(v, false, (n+1)*sizeof(v[0]));
		
		for(i = 0; i < r; i++){
			int aux;
			cin >> aux;
			v[aux] = true;
		}
		
		for(i = 1; i <= n; i++){
			if(!v[i]){
				cout << i << " ";
			}else{
				cont++;
			}
		}
		
		if(cont == n){
			cout << '*';
		}
		cout << endl;
	}
}
