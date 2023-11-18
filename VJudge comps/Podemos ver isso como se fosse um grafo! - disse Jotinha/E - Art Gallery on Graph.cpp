#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

void bfs(vector<vector<int>> &graph, vector<int> &dist, priority_queue<pair<int, int>>&pq)
{
    while (!pq.empty())
    {
        int node = pq.top().second;
        int peso = pq.top().first;
        pq.pop();
        if(peso < 0  || dist[node] >= peso) continue;

        dist[node] = max(dist[node], peso);
        if (peso == 0)
            continue;

        for (auto v : graph[node])
        {
            if (dist[v] < peso - 1)
            {
                pq.push({peso - 1, v});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> graph(n + 1);
    vector<pii> Guards(k);
    vector<int> dist(n + 1, -1);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    priority_queue<pair<int, int>>pq;

    for (int i = 0; i < k; i++)
    {
		int x,y;
        cin >> x >> y;
        pq.push({y,x});
    }
    bfs(graph, dist, pq);
    
    vector<int> fim;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] >= 0)
        {
            fim.push_back(i);
        }
    }
    cout << fim.size() << endl;
    for (auto i : fim)
    {
        cout << i << " ";
    }
    cout << endl;
}
