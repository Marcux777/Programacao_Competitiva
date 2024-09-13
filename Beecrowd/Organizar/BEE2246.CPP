#include <bits/stdc++.h>
using namespace std;

int mat[201][201];
int vis[201][201];
int cont = 0, aux = 100000;

void bt(int n, int m, int i, int j)
{
	cont++;
	vis[i][j] = 1;
	if (i > 0 && mat[i - 1][j] == mat[i][j] && vis[i - 1][j] == 0)
	{
		bt(n, m, i - 1, j);
	}
	if (i < n - 1 && mat[i + 1][j] == mat[i][j] && vis[i + 1][j] == 0)
	{
		bt(n, m, i + 1, j);
	}
	if (j > 0 && mat[i][j - 1] == mat[i][j] && vis[i][j - 1] == 0)
	{
		bt(n, m, i, j - 1);
	}
	if (j < m - 1 && mat[i][j + 1] == mat[i][j] && vis[i][j + 1] == 0)
	{
		bt(n, m, i, j + 1);
	}
}
int main()
{
	int n, m;
	int i, j;
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> mat[i][j];
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			vis[i][j] = 0;
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (vis[i][j] != 1)
			{
				cont = 0;
				bt(n, m, i, j);
				if (cont < aux)
				{
					aux = cont;
				}
			}
		}
	}
	cout << aux << endl;
}
