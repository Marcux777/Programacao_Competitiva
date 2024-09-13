#include <bits/stdc++.h>
using namespace std;
int main()
{
	int num, n;
	char v1[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	char v2[27];
	cin >> num;
	while (num--)
	{
		int troca = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> v2[i];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (v1[i] == v2[j] && i != j)
				{
					char aux = v2[j];
					v2[j] = v2[i];
					v2[i] = aux;
					troca++;
				}
			}
		}
		if (troca > 1)
		{
			cout << "There aren't the chance." << endl;
		}
		else
		{
			cout << "There are the chance." << endl;
		}
	}
}
