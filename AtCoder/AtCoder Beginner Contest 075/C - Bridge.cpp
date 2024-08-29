#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;
int cont;

void dfs(int v, int p = -1)
{
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v])
    {
        if (to == p)
            continue;
        if (visited[to])
        {
            low[v] = min(low[v], tin[to]);
        }
        else
        {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                cont++;
        }
    }
}

void find_bridges()
{
    timer = cont = 0;
    visited.assign(n+1, false);
    tin.assign(n + 1, -1);
    low.assign(n + 1, -1);
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
            dfs(i);
    }
    cout << cont << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("saida.txt", "w", stdout);
    cin >> n >> m;
    adj.assign(n + 1, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    find_bridges();
}