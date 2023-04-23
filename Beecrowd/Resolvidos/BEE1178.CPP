#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double x, y;
	int n[100], i;
	i = 0;
	cin >> x;
	cout << setprecision(4) << fixed;
	cout << "N[" << i << "] = " << x << endl;
	for (i = 1; i < 100; i++)
	{

		y = x / 2;
		x = y;
		cout << setprecision(4) << fixed;
		cout << "N[" << i << "] = " << y << endl;
	}
}