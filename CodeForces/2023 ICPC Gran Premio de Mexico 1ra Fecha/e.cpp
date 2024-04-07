#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

vector<vector<int>> adj;
vector<int> vis;
vector<int> v;
vector<set<int>> dp;
unordered_map<int, int> remember;
int c;
int dfs(int u)
{
    vis[u] = true;
    for (auto v : adj[u])
    {
        if (!vis[v])
        {
            dp[u].insert(v);
            dp[u].insert(dp[v].begin(), dp[v].end());
            dfs(v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    v = vector<int>(n + 1);
    adj.resize(n + 1);
    for (auto i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    int q1 = 1;
    while (q1 <= q)
    {
        // c = 0;
        vis.assign(n + 1, false);
        int x, amount;
        cin >> x >> amount;
        c = 1;
        dfs(x);
        int f = c;

        if (amount % f == 0)
        {
            for (int i = 1; i <= n; i++)
            {
                if (vis[i])
                {
                    v[i] -= amount / f;
                    if (v[i] <= 0 && !remember.count(i))
                    {
                        remember[i] = q1;
                    }
                }
            }
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                if (vis[i])
                {
                    v[i] -= amount / f;
                    if (v[i] <= 0 && !remember.count(i))
                    {
                        remember[i] = q1;
                    }
                }
            }
            v[x] -= amount % f;
            if (v[x] <= 0 && !remember.count(x))
            {
                remember[x] = q1;
            }
        }
        q1++;
    }
    for (int i = 1; i <= n; i++)
    {
        int a = remember[i];
        cout << (a == 0 ? -1 : a) << endl;
    }
}