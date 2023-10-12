#include <bits/stdc++.h>

using namespace std;

char v[26][26];
bool vis[26][26] = {false};
int tam;

void floodfill(int i, int j, int m)
{
	vis[i][j] = true;
	tam++;
	if (i > 0 && v[i - 1][j] == '1' && !vis[i - 1][j])
	{
		floodfill(i - 1, j, m);
	}
	if (i < m && v[i + 1][j] == '1' && !vis[i + 1][j])
	{
		floodfill(i + 1, j, m);
	}
	if (j > 0 && v[i][j - 1] == '1' && !vis[i][j - 1])
	{
		floodfill(i, j - 1, m);
	}
	if (v[i][j + 1] == '1' && !vis[i][j + 1])
	{
		floodfill(i, j + 1, m);
	}
	if (i > 0 && v[i - 1][j - 1] == '1' && !vis[i - 1][j - 1])
	{
		floodfill(i - 1, j - 1, m);
	}
	if (i < m && v[i + 1][j + 1] == '1' && !vis[i + 1][j + 1])
	{
		floodfill(i + 1, j + 1, m);
	}
	if (i < m && j > 0 && v[i + 1][j - 1] == '1' && !vis[i + 1][j - 1])
	{
		floodfill(i + 1, j - 1, m);
	}
	if (i > 0 && v[i - 1][j + 1] == '1' && !vis[i - 1][j + 1])
	{
		floodfill(i - 1, j + 1, m);
	}
}

int main()
{
	int t, max, i;
	cin >> t;
	cin.ignore();
	cin.ignore();
	while (t--)
	{
		memset(vis, false, sizeof(vis));
		memset(v, 0, sizeof(v));
		max = i = 0;
		while (gets(v[i]) && v[i][0] != '\0')
		{
			i++;
		}
		int m = i;
		for (i = 0; i < m; i++)
		{
			for (int j = 0; v[i][j]; j++)
			{
				if (!vis[i][j] && v[i][j] == '1')
				{
					tam = 0;
					floodfill(i, j, m);
					if (tam > max)
					{
						max = tam;
					}
				}
			}
		}
		cout << max << endl;
		if (t)
		{
			cout << endl;
		}
	}
}