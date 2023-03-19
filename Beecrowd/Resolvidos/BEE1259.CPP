#include <bits/stdc++.h>
using namespace std;
int main(){
	vector <int> a, par, impar;
	int n, num;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> num;
		if(num%2 == 0){
			par.push_back(num);
		}else{
			impar.push_back(num);
		}
	}
	sort(par.begin(), par.end());
	sort(impar.begin(), impar.end(), greater<int>());
	for(int i = 0; i < par.size(); i++){
		cout << par[i] << endl;
	}
	for(int i = 0; i < impar.size(); i++){
		cout << impar[i] << endl;
	}
}
