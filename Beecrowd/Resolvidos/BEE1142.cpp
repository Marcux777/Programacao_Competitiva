#include <iostream>

using namespace std;

int main(){
	int N, i;
	cin >> N;
	
	for (i = 0; i < N*4;){
		cout << i + 1 << " " << i + 2 << " " << i + 3 << " PUM" << endl;
		i+=4;
	}
}