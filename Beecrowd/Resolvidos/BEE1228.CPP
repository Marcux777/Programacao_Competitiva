#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, v1[24], v2[24];
	while (cin >> n)
	{
		int c = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> v1[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> v2[i];
		}
		int i, j;
		i = j = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (v1[i] == v2[j] && i != j)
				{
					if (i < j)
					{
						while (i < j && j > 0)
						{
							int aux = v2[j];
							v2[j] = v2[j - 1];
							v2[j - 1] = aux;
							j--;
							c++;
						}
					}
					else
					{
						while (i > j && j < n - 1)
						{
							int aux = v2[j];
							v2[j] = v2[j + 1];
							v2[j + 1] = aux;
							j++;
							c++;
						}
					}
				}
			}
		}
		cout << c << endl;
	}
}
