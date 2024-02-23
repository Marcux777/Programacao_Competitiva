#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q;
    int c = 0;
    while (cin >> n >> m >> q && (n || m || q))
    {
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
        for (int i = 1; i <= n; i++)
        {
            dist[i][i] = 0;
        }

        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            dist[a][b] = dist[b][a] = c;
        }

        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {

                    dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
                }
            }
        }
        if(c) cout << endl ;
        cout << "Case #" << ++c << endl;
        while (q--)
        {
            int x, y;
            cin >> x >> y;
            ((dist[x][y] == INF) ? cout << "no path" : cout << dist[x][y]);

            cout << endl;
        }
    }
}