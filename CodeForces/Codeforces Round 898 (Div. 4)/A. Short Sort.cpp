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
		
		string s;
		cin >> s;
		if(op(s)){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}
}