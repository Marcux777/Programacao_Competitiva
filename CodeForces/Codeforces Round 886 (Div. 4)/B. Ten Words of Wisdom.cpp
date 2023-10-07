#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n;
	cin>>n;
	while(n--){
		int t;
		cin >> t;
		int id, maior = -1100000;
		for(int i = 1; i <= t; i++){
			int x, y;
			cin >>x >> y;
			if(x <= 10 && y > maior){
				maior = y;
				id = i;
			}
		}
		cout << id << endl;
	}
}