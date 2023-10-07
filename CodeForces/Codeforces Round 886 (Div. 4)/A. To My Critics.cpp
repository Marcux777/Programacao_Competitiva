#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n;
	cin>>n;
	while(n--){
		vector<int>v;
		for(int i = 0; i < 3;i ++){
			int x;
			cin >> x;
			v.push_back(x);
		}
		bool resp = false;
		for(int i = 0; i < 3 && !resp; i++){
			for(int j = i+1; j < 3; j++){
				int s = v[i] + v[j];
				if(s >= 10){
					resp = true;
				}
			}
		}
		if(resp){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
}
}