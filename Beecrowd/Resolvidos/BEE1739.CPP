#include <bits/stdc++.h>

using namespace std;

bool valido(long long int n)
{
	while (n > 0)
	{
		if (n % 10 == 3)
		{
			return true;
		}
		n /= 10;
	}
	return false;
}

int main()
{
	long long int n;
	long long int num;
	long long fibo[1020];
	int i;

	fibo[0] = 0;
	fibo[1] = 1;

	for (i = 2; i <= 1000; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];

	while (cin >> n)
	{
		for (i = 2; i <= 1000; i++)
		{
			if (valido(fibo[i]) || fibo[i] % 3 == 0)
				n--;
			if (!n)
				break;
		}
		cout << fibo[i] << '\n';
	}
}