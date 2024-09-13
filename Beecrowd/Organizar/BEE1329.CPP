#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, a;
	cin >> n;
	int m, j;
	while (n)
	{
		m = j = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a;
			if (a == 0)
			{
				m++;
			}
			else
			{
				j++;
			}
		}

		cout << "Mary won " << m;
		cout << " times and John won " << j << " times" << endl;
		cin >> n;
	}
}
