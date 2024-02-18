#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define endl '\n'
const int INF = 1e18;
const int MAXN = 2e5 + 5;

vector<pair<int, int>> adj[MAXN];
int dist[MAXN];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 1; i < N; i++)
    {
        int A, B, X;
        cin >> A >> B >> X;
        adj[i - 1].push_back({i, A});
        adj[i - 1].push_back({X - 1, B});
    }

    fill(dist, dist + N, INF);
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d != dist[u])
            continue;

        for (auto e : adj[u])
        {
            int v = e.first;
            int w = e.second;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << dist[N - 1] << "\n";
}