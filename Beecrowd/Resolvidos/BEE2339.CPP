#include <iostream>
using namespace std;
int main(){
	int C, P, F;
	cin >> C >> P >> F;
	if(P >= C*F){
		cout << "S" << endl;
	}
	else {
		cout << "N" << endl;
	}
}
