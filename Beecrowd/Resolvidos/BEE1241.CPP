#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	while(n--){
		string s1, s2;
		bool encaixa = true;
		cin >> s1 >> s2;
		if(s1.size() >= s2.size()){
			int j = s1.size()-1;
			for(int i = s2.size()-1; i >= 0; i--,j--){
				if(s1[j] != s2[i]){
					encaixa = false;
				}
			}
		}else{
			encaixa = false;
		}
		if(!encaixa){
			cout << "nao encaixa" << endl;
		}else{
			cout << "encaixa" << endl;
		}
	}
}
