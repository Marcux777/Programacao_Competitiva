#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topsort(const vector<vector<int>> &adjlist)
{
    int n = adjlist.size();
    vector<int> grau(n, 0);
    for (int u = 0; u < n; u++)
    {
        for (int v : adjlist[u])
        {
            grau[v]++;
        }
    }
    queue<int> q;
    for (int u = 0; u < n; u++)
    {
        if (grau[u] == 0)
        {
            q.push(u);
        }
    }
    vector<int> order;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : adjlist[u])
        {
            if (--grau[v] == 0)
            {
                q.push(v);
            }
        }
    }
    if (order.size() != n)
    {
        return vector<int>();
    }
    else
    {
        return order;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("saida.txt", "w", stdout);
    int n;
    while (cin >> n)
    {
        vector<vector<int>> adjlist(n);
        for (int u = 0; u < n; u++)
        {
            int m;
            cin >> m;
            for (int i = 0; i < m; i++)
            {
                int v;
                cin >> v;
                v--;
                adjlist[v].push_back(u);
            }
        }
        vector<int> order = topsort(adjlist);
        if (order.empty())
        {
            cout << "-1" << endl;
        }
        else
        {
            vector<int> time(n, 0);
            int max_time = 0;
            for (int u : order)
            {
                for (int v : adjlist[u])
                {
                    time[v] = max(time[v], time[u] + 1);
                }
                max_time = max(max_time, time[u]);
            }
            cout << max_time + 1 << endl;
        }
    }
    return 0;
}
