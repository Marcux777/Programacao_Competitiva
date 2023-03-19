#include <bits/stdc++.h>
using namespace std;
int main(){
	string a;
	vector<string>v;
	int n;
	while(cin >> n){
		for(int i = 0; i < n; i++){
			cin >> a;
			v.push_back(a);
			a.clear();
		}
		sort(v.begin(), v.end());
		for(int i = 0; i < v.size(); i++){
			cout << v[i] << endl;
		}
		v.clear();
	}
}
