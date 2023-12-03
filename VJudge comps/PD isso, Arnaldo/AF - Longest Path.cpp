#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define endl '\n'
#define INF LLONG_MAX

vector<int> DP;
vector<vector<int>> graph;
vector<bool> vis;
int N, M;

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
    cin >> N >> M;
    graph.resize(N + 1);
    vis.assign(N + 1, false);
    DP.resize(N + 1);
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    for (int i = 1; i <= N; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    cout << *max_element(DP.begin(), DP.end()) << endl;
}