#include <bits/stdc++.h>

using namespace std;

char g[101][101];
bool vis[101][101];
int cont;

void floodfill(int i, int j, int n)
{
    vis[i][j] = true;
    if (i > 0 && g[i - 1][j] == 'x' || g[i - 1][j] == '@')
    {
        if (!vis[i - 1][j])
        {
            floodfill(i - 1, j, n);
        }
    }

    if (j > 0 && g[i][j - 1] == 'x' || g[i][j - 1] == '@')
    {
        if (!vis[i][j - 1])
        {
            floodfill(i, j - 1, n);
        }
    }

    if (i < n && g[i + 1][j] == 'x' || g[i + 1][j] == '@')
    {
        if (!vis[i + 1][j])
        {
            floodfill(i + 1, j, n);
        }
    }

    if (j < n && g[i][j + 1] == 'x' || g[i][j + 1] == '@')
    {
        if (!vis[i][j + 1])
        {
            floodfill(i, j + 1, n);
        }
    }
}

int main()
{
    int t, n, caso = 0;
    cin >> t;
    while (t--)
    {
        cont = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> g[i][j];
                vis[i][j] = false;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (g[i][j] == 'x')
                {
                    if (!vis[i][j])
                    {
                        cont++;
                        floodfill(i, j, n);
                    }
                }
            }
        }
        cout << "Case " << ++caso << ": ";
        cout << cont << endl;
    }
}