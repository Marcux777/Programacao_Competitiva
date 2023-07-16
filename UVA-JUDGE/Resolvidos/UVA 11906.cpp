#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <set>

using namespace std;

int grid[105][105];
bool visited[105][105];

pair<int, int> bfs(int r, int c, int m, int n)
{
    int dr[8] = {m, m, -m, -m, n, -n, n, -n};
    int dc[8] = {n, -n, n, -n, m, m, -m, -m};
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    visited[0][0] = true;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        set<pair<int, int>> adj;
        for (int k = 0; k < 8; k++)
        {
            int i = dr[k] + p.first;
            int j = dc[k] + p.second;
            if (i >= 0 && j >= 0 && i < r && j < c && grid[i][j] != -1)
            {
                adj.insert(make_pair(i, j));
            }
        }
        for (auto idx : adj)
        {
            grid[idx.first][idx.second]++;
            if (!visited[idx.first][idx.second])
            {
                visited[idx.first][idx.second] = true;
                q.push(make_pair(idx.first, idx.second));
            }
        }
    }
    int par, impar;
    par = impar = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if ((grid[i][j] != -1 && grid[i][j] != 0) || (i == 0 && j == 0))
            {
                if (grid[i][j] & 1)
                {
                    impar++;
                }
                else
                {
                    par++;
                }
            }
        }
    }
    return make_pair(par, impar);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // freopen("saida.txt", "w", stdout);
    int t, r, c, m, n, w, x, y, caso = 0;
    cin >> t;
    while (t--)
    {
        cin >> r >> c >> m >> n;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                grid[i][j] = 0;
                visited[i][j] = false;
            }
        }
        cin >> w;
        for (int i = 0; i < w; i++) // Marcando as poças
        {
            cin >> x >> y;
            grid[x][y] = -1;
        }
        pair<int, int> p = bfs(r, c, m, n);
        cout << "Case " << ++caso << ": " << p.first << " " << p.second << endl;
    }
}