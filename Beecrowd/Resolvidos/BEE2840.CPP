#include <iostream>
using namespace std;
int main(){
	int r, l;
	float pi, vol;
	cin >> r >> l;
	pi = 3.1415;
	vol = (4.0/3.0)*((r*r*r)*pi);
	cout << (int)l/(int)vol << endl;
}
