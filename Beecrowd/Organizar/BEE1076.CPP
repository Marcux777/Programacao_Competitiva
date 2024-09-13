#include <bits/stdc++.h>
using namespace std;

bool mat[100][100] = {false};
bool vis[100];
// vector <int> adjlist[100];
int cont = 0;

void zera()
{
	cont = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			mat[i][j] = false;
		}
		vis[i] = false;
	}
}
void dfs(int n, int a)
{
	vis[n] = true;
	int i;

	for (i = 0; i < a; i++)
	{
		// int k = adjlist[v][i];
		if (mat[n][i] && !vis[i])
		{
			cont++;
			dfs(i, a);
		}
	}
}

int main()
{
	int t, x, y;
	int n, v, a;
	cin >> t;
	while (t--)
	{
		zera();
		cin >> n;
		cin >> v >> a;
		for (int i = 0; i < a; i++)
		{
			cin >> x >> y;
			mat[x][y] = true;
			mat[y][x] = true;
		}
		dfs(n, v);
		cout << cont * 2 << endl;
	}
}