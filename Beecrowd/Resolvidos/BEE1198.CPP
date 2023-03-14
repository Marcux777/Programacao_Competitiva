#include <iostream>
using namespace std;
int main(){
	long long int n1, n2;
	while(cin >> n1 >> n2){
		if(n2 > n1){
			cout << n2-n1 << endl;
		}else{
			cout << (n2-n1) * -1 << endl;
		}
	}
}
