#include <bits/stdc++.h>

using namespace std;

char mapa[21][21];
bool vis[21][21];
char land;
int cont, maior_cont;

void dfs(int x, int y, int limLinha, int limCol)
{
    if (y < 0)
        y = limCol - 1;
    if (y >= limCol)
        y = 0;
    if (x < 0 || x >= limLinha || vis[x][y] || mapa[x][y] != land)
    {
        return;
    }
    maior_cont++;
    vis[x][y] = true;

    dfs(x - 1, y, limLinha, limCol);

    dfs(x + 1, y, limLinha, limCol);

    dfs(x, y - 1, limLinha, limCol);

    dfs(x, y + 1, limLinha, limCol);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("saida.txt", "w", stdout);
    int m, n;
    while (cin >> n >> m)
    {
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mapa[i][j];
            }
        }
        int x, y;
        cin >> x >> y;
        land = mapa[x][y];
        dfs(x, y, n, m);
        cont = 0;
        maior_cont = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                maior_cont = 0;
                dfs(i, j, n, m);
                cont = max(maior_cont, cont);
            }
        }
        cout << cont << endl;
    }
}
