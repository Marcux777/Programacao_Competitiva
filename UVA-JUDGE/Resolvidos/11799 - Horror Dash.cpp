#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	int t, maior, caso = 0, aux;
	cin >> t;
	while(t--){
		maior = 0;
		
		getchar();
		getline(cin, s);
		
		for(int i = 0; i < s.size(); i++){
			if(s[i] != ' ' && s[i] != '\0'){
				aux = s[i] - '0';
				if(s[i+1] != ' '){
					for(int j = i+1; j < s.size() && s[j] != ' '; j++){
						aux = aux*10;
						aux = aux + (s[j] - '0');
					} 
					
				}
				//cout << aux << endl;
				if(aux > maior){
					maior = aux;
				}
			}
		}
		cout << "Case " << ++caso << ": ";
		cout << maior << endl;
		s.clear();
	}
}
