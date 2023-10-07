#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	double somax, somay, somaz;
	somax = somay = somaz = 0.0;
	for(int i = 0; i < n; i++){
		int x, y, z;
		cin >> x >> y >> z;
		somax += x;
		somay += y;
		somaz += z;
	}
	if(somax != 0 || somay != 0 || somaz != 0){
		cout << "NO\n";
	}else{
		cout << "YES\n";
	}
}