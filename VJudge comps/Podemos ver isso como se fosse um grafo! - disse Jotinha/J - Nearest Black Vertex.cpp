#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

void bfs1(int p, int d, vector<bool> &vis, vector<vector<int>> &g)
{
    queue<int> q;
    vector<int> dist(g.size(), INF);
    q.push(p);
    dist[p] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (dist[u] == d)
        {
            continue;
        }
        vis[u] = false;
        for (const int v : g[u])
        {
            if (dist[v] == INF)
            {
                q.push(v);
                dist[v] = dist[u] + 1;
            }
        }
    }
}

bool bfs2(int p, int d, vector<bool> &vis, vector<vector<int>> &g)
{
    queue<int> q;
    vector<int> dist(g.size(), INF);
    q.push(p);
    dist[p] = 0;
    bool isValid = false;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (dist[u] < d && vis[u])
            return false;
        if (dist[u] == d)
        {
            isValid |= vis[u];
            continue;
        }

        for (const int &v : g[u])
        {
            if (dist[v] == INF)
            {
                q.push(v);
                dist[v] = dist[u] + 1;
            }
        }
    }
    return isValid;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int K;
    cin >> K;
    vector<int> p(K), d(K);
    vector<bool> vis(n, true);
    for (int i = 0; i < K; i++)
    {
        cin >> p[i] >> d[i];
        p[i]--;
        bfs1(p[i], d[i], vis, g);
    }

    bool isValid = true;
    for (int i = 0; i < K; i++)
        isValid &= bfs2(p[i], d[i], vis, g);
    if (!isValid)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
        for (int i = 0; i < n; i++)
            cout << (vis[i] ? 1 : 0);
        cout << endl;
    }
    return 0;
}
