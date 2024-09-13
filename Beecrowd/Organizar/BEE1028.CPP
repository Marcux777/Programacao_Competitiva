#include <iostream>
using namespace std;

int MDC(int a, int b)
{
	if (a == 0)
		return b;
	return MDC(b % a, a);
}

int main()
{
	int n, x, y;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		cout << MDC(x, y) << endl;
	}
}
