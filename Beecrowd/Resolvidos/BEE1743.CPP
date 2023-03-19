#include <iostream>
 
using namespace std;
 
int main() {
	int i = 0, x[5], y[5];
	for( i = 0; i < 5; i++){
		cin >> x[i];
	}
	for( i = 0; i < 5; i++){
		cin >> y[i];
	}
	for( i = 0; i < 5; i++){
		if(x[i] == y[i]){
			i += 100;
		}
	}
	if(i < 10){
		cout << 'Y' << endl;
	} else{
		cout << 'N' << endl;
	}
}