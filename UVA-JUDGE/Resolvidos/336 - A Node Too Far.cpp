#include <bits/stdc++.h>

using namespace std;

int bfs(int start, map<int, vector<int>> &adj, int tle)
{
    queue<int> q;
    int count = 0;
    set<int> vis;
    map<int, int> dist;
    q.push(start);
    vis.insert(start);
    dist[start] = 0;

    while (!q.empty())
    {
        int vertex = q.front();
        if (dist[vertex] <= tle)
        {
            count++;
        }
        q.pop();

        for (auto it : adj[vertex])
        {
            if (vis.find(it) == vis.end())
            {
                q.push(it);
                vis.insert(it);
                dist[it] = dist[vertex] + 1;
            }
        }
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ans = 0;
    //freopen("saida.txt", "w", stdout);
    int m;
    while (cin >> m && m)
    {
        map<int, vector<int>> graph;
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        int tam = graph.size();
        int s, tle;
        //cout << tam << endl;
        while (cin >> s >> tle && (s || tle))
        {
            cout << "Case " << ++ans << ": ";
            if(graph.find(s) == graph.end()) cout << tam;
            else cout << abs(tam - bfs(s, graph, tle));
            cout << " nodes not reachable from node " << s << " with TTL = " << tle << '.' << endl;
        }
    }
}