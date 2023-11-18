#include <bits/stdc++.h>

// MUAAAHAHAHAHAHAHHAHAHHAHAHHA (RISADA MALIGNA)

using namespace std;

#define ll long long int

int n;
vector<vector<int>> graph;
vector<ll> subTree, dist;

void dfsa(int v, int parent)
{
    subTree[v] = 1;
    for (auto u : graph[v])
    {
        if (u != parent)
        {
            dfsa(u, v);
            subTree[v] += subTree[u]; // inclui a subArvore u a subArvore de v
            // distâncias do nó u a todos os outros nós
            // em sua subárvore
            // e o tamanho da subárvore do nó u à soma das distâncias do nó v
            dist[v] += dist[u] + subTree[u];
        }
    }
}

void dfsb(int v, int parent)
{
    for (auto u : graph[v])
    {
        if (u != parent)
        {
            //  soma das distâncias do nó u
            //  a todos os outros nós com base na soma das distâncias do nó v
            dist[u] = dist[v] + n - 2 * subTree[u];
            dfsb(u, v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    graph.assign(n + 1, vector<int>());
    subTree.assign(n + 1, 0);
    dist.assign(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfsa(1, 0);
    dfsb(1, 0);

    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
}