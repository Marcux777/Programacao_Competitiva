#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	double dist, media = 0;
	int cont = 0;
	while(getline(cin, s)){
		cin >> dist;
		cont++;
		media += dist;
		//cout << media/cont << endl;
		getline(cin, s);
	}
	cout << fixed << setprecision(1);
	cout << media/cont << endl;
	
}
