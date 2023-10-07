#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		int n, k, op = 0;
		cin >> n >> k;
		cin >> s;
		for(int i = 0; i < n; i++){
			if(s[i] == 'B'){
				op++;
				for(int j = 0; j < k && j+i < n; j++){
					s[i+j] = 'W';
				}
			}
		}
		cout << op << endl;
	}
}