#include <bits/stdc++.h>
using namespace std;

int main()
{
	float a, b, c, x;
	cin >> a >> b;
	c = b - a;
	x = (100.0 * c) / a;
	cout << fixed << setprecision(2) << x << "%" << endl;
}
