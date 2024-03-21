#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define inf LLONG_MAX
#define Ninf LLONG_MIN
#define mod 1000000007

void BFS(int s, vector<vector<int>> &adj)
{
    queue<int> queue;
    vector<bool> visited(adj.size(), false);

    visited[s] = true;
    queue.push(s);

    while (!queue.empty())
    {
        int u = queue.front();
        queue.pop();
        cout << u << " ";

        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                queue.push(v);
            }
        }
    }
    for(int i = 1; i <= adj.size(); i++){
        if(visited[i]) cout << i << " ";
    }
    cout << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x;
        cin >> n >> m >> x;
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < m; i++)
        {
            int y;
            char c;
            cin >> y >> c;
            for (int j = x; j <= n; j += y)
            {
                if (c == '1')
                {
                    adj[x].push_back(j);
                }
                else
                {
                    if (c == '2')
                    {
                        adj[j].push_back(x);
                    }
                    else
                    {
                        adj[j].push_back(x);
                        adj[x].push_back(j);
                    }
                }
            }
        }
        BFS(x, adj);
    }
}