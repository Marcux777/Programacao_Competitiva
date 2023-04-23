#include <bits/stdc++.h>

using namespace std;

void inicializa(int v[])
{
	for (int i = 0; i < 2001; i++)
	{
		v[i] = 0;
	}
}

int main()
{
	int n, v[2001];
	inicializa(v);
	cin >> n;
	int vet[n];
	for (int i = 0; i < n; i++)
	{
		cin >> vet[i];
	}
	for (int i = 0; i < n; i++)
	{
		int k = vet[i];
		v[k]++;
	}
	for (int i = 0; i < 2001; i++)
	{
		if (v[i] != 0)
		{
			cout << i << " aparece " << v[i] << " vez(es)" << endl;
		}
	}
}
