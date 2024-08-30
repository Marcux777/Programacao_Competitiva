#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	
	double pi;
	double raio;
	
	pi=3.14159;
		
	cin >> raio;
	
	cout << fixed << setprecision(4);
	cout << "A=" << pi* (raio*raio) << endl;
	
	return 0;
}