#include <iostream>
using namespace std;
int main(){
	int n, cont = 0;
	while(cin >> n){
		while(n!=1){
			n/=2;
			cont++;
		}
		cout << cont << endl;
		cont = 0;
	}
}


