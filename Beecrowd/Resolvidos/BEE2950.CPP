#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int n, x, y;
	float icm;
	cin >> n >> x >> y;
	icm = (float)n / (x + y);
	cout << setprecision(2) << fixed;
	cout << icm << endl;
}
