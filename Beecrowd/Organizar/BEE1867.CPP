#include <iostream>
using namespace std;

int diminui(long long x)
{
	while (x >= 10)
	{
		long long aux = x;
		long long s = 0;

		while (aux)
		{
			s += aux % 10;
			aux /= 10;
		}
		x = s;
	}
	return x;
}
int main()
{
	string a, b;
	long long n1, n2;
	cin >> a >> b;
	while (a != "0" || b != "0")
	{
		n1 = 0;
		n2 = 0;

		for (int i = 0; i < a.size(); ++i)
		{
			n1 += a[i] - '0';
		}
		for (int i = 0; i < b.size(); ++i)
		{
			n2 += b[i] - '0';
		}
		n1 = diminui(n1);
		n2 = diminui(n2);
		if (n1 > n2)
		{
			cout << 1 << endl;
		}
		else
		{
			if (n2 > n1)
			{
				cout << 2 << endl;
			}
			else
			{
				cout << 0 << endl;
			}
		}
		cin >> a >> b;
	}
}