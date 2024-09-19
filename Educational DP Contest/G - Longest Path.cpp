#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define inf LLONG_MAX
#define Ninf LLONG_MIN

vector<int> DP;
vector<vector<int>> graph;
vector<bool> vis;
int n, m;

void dfs(int u)
{
    vis[u] = true;

    for (auto v : graph[u])
    {
        if (!vis[v])
        {
            dfs(v);
        }
        DP[u] = max(DP[u], DP[v] + 1);
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    graph.resize(n + 1);
    vis.assign(n+1, false);
    DP.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i);
    }
    cout << *max_element(DP.begin(), DP.end()) << endl;
}