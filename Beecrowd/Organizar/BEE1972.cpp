#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

bool isValid(int row, int col, int ROW, int COL)
{
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

void dijkstra(vector<vector<int>> grid, int ROW, int COL, int x, int y)
{
    vector<vector<int>> dist(ROW, vector<int>(COL, INF));

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    pq.push(make_pair(grid[x][y], make_pair(x, y)));
    dist[x][y] = 0;

    while (!pq.empty())
    {
        pair<int, pair<int, int>> current = pq.top();
        pq.pop();

        int i = current.second.first;
        int j = current.second.second;

        if (grid[i][j] == 100000000)
        {
            continue;
        }

        for (int k = 0; k < 4; k++)
        {
            int ni = i + dx[k], nj = j + dy[k];
            if (isValid(ni, nj, ROW, COL) && dist[i][j] + grid[ni][nj] < dist[ni][nj])
            {
                dist[ni][nj] = dist[i][j] + grid[ni][nj];
                pq.push(make_pair(dist[ni][nj], make_pair(ni, nj)));
            }
        }
    }

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (grid[i][j] == 11)
            {
                (dist[i][j] == INF) ? cout << "ARTSKJID" : cout << dist[i][j] - 11;
            }
        }
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("saida.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '.')
                grid[i][j] = 0;
            else if (s[j] == '#')
                grid[i][j] = 100000000;
            else if (s[j] == 'H')
                grid[i][j] = 10;
            else if (s[j] == 'E')
                grid[i][j] = 11;
            else
                grid[i][j] = (int)s[j] - '0';
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 10)
            {
                dijkstra(grid, n, m, i, j);
            }
        }
    }
}
