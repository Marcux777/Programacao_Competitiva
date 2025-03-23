#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;

int dfs(int node, vector<bool> &visited, int ant, vector<int> &resp)
{
    visited[node] = true;
    if (graph[node].empty())
    { // chegou aqui, não tem filho
        resp[node] = 0;
    }
    else
    {
        for (auto u : graph[node])
        {
            if(!visited[u]){
                resp[node] += dfs(u, visited, node, resp) + 1;
            }
        }
    }
    return resp[node];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    graph.resize(n + 1, vector<int>());
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        // graph[i].push_back(x);
        graph[x].push_back(i);
    }
    vector<int> resp(n + 1);
    vector<bool> visited(n + 1, false);
    dfs(1, visited, 0, resp);

    for (int i = 1; i <= n; i++)
    {
        cout << resp[i];
        i == n ? cout << endl : cout << " ";
    }
}
