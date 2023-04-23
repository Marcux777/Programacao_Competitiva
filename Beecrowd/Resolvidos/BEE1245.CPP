#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int m[n + 1];
		char l[n + 1];
		int par = 0, inf = -1;
		for (int i = 0; i < n; i++)
		{
			cin >> m[i] >> l[i];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (m[i] == m[j] && l[i] != l[j])
				{
					par++;
					m[j] = inf;
					inf--;
					m[i] = inf;
					inf--;
				}
			}
		}
		cout << par << endl;
		par = 0;
	}
}
