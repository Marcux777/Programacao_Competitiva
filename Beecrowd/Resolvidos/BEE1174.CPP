#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int A[100], i;
	double x;
	for (i = 0; i < 100; i++){
		cin >> x;
		if (x <= 10){
			cout << setprecision(1) << fixed;
			cout << "A[" << i << "] = " << x*1.0 << endl;
		}
	}
}