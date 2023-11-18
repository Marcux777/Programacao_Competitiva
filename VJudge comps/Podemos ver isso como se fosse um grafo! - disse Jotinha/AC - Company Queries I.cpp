#include <bits/stdc++.h>
using namespace std;

// https://cp-algorithms.com/graph/lca_binary_lifting.html

int n, l;
vector<int> adj[200005];

int timer;
int tin[200005], tout[200005];
int up[200005][21];

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i - 1]][i - 1];

    for (int u : adj[v])
    {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i)
    {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root)
{
    timer = 0;
    l = ceil(log2(n));
    dfs(root, 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("saida.txt", "w", stdout);
    int q;
    cin >> n >> q;

    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    n++;
    preprocess(1);
    while (q--)
    {
        int x, k;
        cin >> x >> k;
        int boss = x;
        for (int i = 0; i <= 20; i++)
        {
            if (k & (1 << i))
                boss = up[boss][i];
        }

        (boss == 0) ? cout << -1 : cout << boss;
        cout << endl;
    }
}
