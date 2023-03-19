#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c;
	while(cin >> a >> b >> c){
		if(a == 1 && b == 0 && c == 0){
			cout << "A" << endl;
		}
		if(a == 0 && b == 1 && c == 1){
			cout << "A" << endl;
		}
		if(a == 0 && b == 1 && c == 0){
			cout << "B" << endl;
		}
		if(a == 1 && b == 0 && c == 1){
			cout << "B" << endl;
		}
		if(a == 1 && b == 1 && c == 0){
			cout << "C" << endl;
		}
		if(a == 0 && b == 0 && c == 1){
			cout << "C" << endl;
		}
		if(a == 0 && b == 0 && c == 0){
			cout << '*' << endl;
		}
		if(a == 1 && b == 1 && c == 1){
			cout << '*' << endl;
		}
	}
	
}
