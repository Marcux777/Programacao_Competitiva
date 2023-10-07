#include <bits/stdc++.h>

using namespace std;

int num(map<int, int>& mp){
	int maior = -1;
	for(auto i : mp){
		if(i.second >= 3){
			maior = i.first;
		}
	}
	return maior;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		map<int, int>mp;
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			if(mp.find(x) != mp.end()){
				mp[x]++;
			}else{
				mp[x] = 1;
			}
		}
		cout << num(mp) << endl;
	}
}