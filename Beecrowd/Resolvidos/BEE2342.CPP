#include <iostream>
 
using namespace std;
 
int main() {
	long long int a, b, c, d;
	char x;
	cin >> a >> b >> x >> c;
	if(x=='+')
	{
		d=b+c;
		if(d>a)
		{
			cout << "OVERFLOW" << endl;
		}
		else
		{
			cout << "OK" << endl;
		}
	}
	else
	{
		d=b*c;
		if(d>a)
		{
			cout << "OVERFLOW" << endl;
		}
		else
		{
			cout << "OK" << endl;
		}
	}
		
}