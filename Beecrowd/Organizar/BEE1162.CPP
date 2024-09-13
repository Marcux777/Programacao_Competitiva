#include <bits/stdc++.h>
using namespace std;

int cont;

void bubbleSort(int v[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (v[i] > v[j])
			{
				int aux = v[i];
				v[i] = v[j];
				v[j] = aux;
				cont++;
			}
		}
	}
}

int main()
{
	int n, tam;
	cin >> n;
	while (n--)
	{
		cont = 0;
		cin >> tam;
		int v[tam];
		for (int i = 0; i < tam; i++)
		{
			cin >> v[i];
		}
		bubbleSort(v, tam);
		cout << "Optimal train swapping takes " << cont << " swaps." << endl;
	}
}
