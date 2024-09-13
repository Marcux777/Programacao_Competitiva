#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	
	string n1;
	double s, v;
	
	cin >> n1;
	cin >> s;
	cin >> v;	
	
	cout << fixed << setprecision(2);
	cout << "TOTAL = R$ " << (((0.15)*v)+ s)<< endl;
	
	return 0;
}