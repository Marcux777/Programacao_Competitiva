#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(unordered_map<int, vector<int>> &graph, int start)
{
    int n = graph.size();
    vector<int> distance(n + 1, -1);
    queue<int> q;

    distance[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int v : graph[node])
        {
            if (distance[v] == -1)
            {
                q.push(v);
                distance[v] = distance[node] + 1;
            }
        }
    }

    return distance;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<int, vector<int>> graph(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    vector<int> dist1 = bfs(graph, 1);

    int node1 = max_element(dist1.begin(), dist1.end()) - dist1.begin();

    vector<int> dist2 = bfs(graph, node1);

    int node2 = max_element(dist2.begin(), dist2.end()) - dist2.begin();

    vector<int> dist3 = bfs(graph, node2);

    for (int i = 1; i <= n; i++)
    {
        int r = max(dist2[i], dist3[i]);
        r == -1 ? cout << 0 << endl : cout << r << " ";
    }

    cout << endl;
}
