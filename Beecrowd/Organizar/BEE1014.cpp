#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	float x; //km
	double y; //litro e consumo
	
	cin >> y;
	cin >> x;
    cout << setprecision(3) << fixed;
	cout << y/x <<" km/l" << endl;
	
	return 0;
}