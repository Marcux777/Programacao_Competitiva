#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	map <int, string> mp;
	while(cin >> n){
		for(int i = 0; i < n; i++){
			int pre;
			string aux;
			cin >> aux;
			cin >> pre;
			mp[pre] = aux;
		}
		int i = 1;
		for(auto it = mp.begin(); it != mp.end(); it++, i++){
			if(i < (int)mp.size()){
				cout << it->second << " ";
			}else{
				cout << it->second << endl;
			}
		}
		//cout << endl;
		mp.clear();
	}
}
