#include <bits/stdc++.h>

using namespace std;

vector<int> parent, dist;
int distFim;

void dfsBob(int u, vector<vector<int>> &g)
{
    for (auto v : g[u])
        if (v != parent[u])
        {
            parent[v] = u;
            dist[v] = dist[u] + 1;
            dfsBob(v, g);
        }
}

void dfsAlice(int u, vector<vector<int>> &g)
{
    if (dist[u] > distFim)
    {
        distFim = dist[u];
    }
    for (int v : g[u])
    {
        if (v != parent[u])
        {
            dfsAlice(v, g);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    distFim = 0;
    int n, x;
    cin >> n >> x;
    vector<vector<int>> graph(n + 1);
    vector<bool> vis(n + 1, false);
    parent.resize(n + 1);
    dist.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    parent[1] = -1;
    dist[1] = 0;
    dfsBob(1, graph);
    int j = x;
    for(int i=0;i<(dist[x]-1)/2;++i)
		j=parent[j];
    distFim = 0;
    dfsAlice(j, graph);
    cout << 2 * distFim << endl;
}