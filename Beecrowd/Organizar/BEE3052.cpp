#include <bits/stdc++.h>

using namespace std;

bool vis[500][500];
char M[501][501];

void floodfill(int limLinha, int limCol, int x, int y)
{
    if (x < 0 || y < 0 || x >= limLinha || y >= limCol || vis[x][y] || M[x][y] == '#')
    {
        return;
    }
    if (M[x][y] == '.' && !vis[x][y])
    {
        M[x][y] = 'o';
    }
    vis[x][y] = true;
    if (M[x][y] == 'o' && M[x + 1][y] == '#')
    {
        // tenho q ir pros lados
        floodfill(limLinha, limCol, x, y + 1);
        floodfill(limLinha, limCol, x, y - 1);
    }
    else
    {
        // senão, tenho q ir pra baixo sempre
        floodfill(limLinha, limCol, x + 1, y);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(vis, false, sizeof(vis));
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> M[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] == 'o')
            {
                floodfill(n, m, i, j);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << M[i][j];
        }
        cout << endl;
    }
    cout << endl;
}