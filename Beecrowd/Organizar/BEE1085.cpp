#include <bits/stdc++.h>

using namespace std;
#define INF INT_MAX
typedef long long ll;

vector<vector<pair<int, string>>> adj;
vector<vector<int>> dist;

void dijkstra()
{
    dist.assign(adj.size(), vector<int>(26, INF));

    for (int i = 0; i < 26; ++i)
        dist[1][i] = 0;

    priority_queue<pair<int, pair<int, char>>, vector<pair<int, pair<int, char>>>, greater<pair<int, pair<int, char>>>> pq;
    pq.push({0, {1, 'a'}});

    while (!pq.empty())
    {
        pair<int, pair<int, char>> front = pq.top();
        pq.pop();
        int d = front.first;
        int v = front.second.first;
        char cx = front.second.second;

        for (auto edge : adj[v])
        {
            char c = edge.second[0];
            if (v != 1 && c == cx)
                continue;
            if (dist[edge.first][c - 'a'] >= dist[v][cx - 'a'] + edge.second.size())
            {
                dist[edge.first][c - 'a'] = dist[v][cx - 'a'] + edge.second.size();
                pq.push({dist[edge.first][c - 'a'], {edge.first, c}});
            }
        }
    }

    int minimum = INF;
    for (int i = 0; i < 26; ++i)
        minimum = min(minimum, dist[2][i]);

    (minimum == INF) ? cout << "impossivel\n" : cout << minimum << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("saida.txt", "w", stdout);

    ll m;

    while (cin >> m && m)
    {
        string origem, destino;
        map<string, int> mp;
        int proxVertice;
        int i;
        string s1, s2, s3;
        proxVertice = 1;
        cin >> origem >> destino;
        mp[origem] = 1;
        mp[destino] = 2;
        proxVertice = 3;

        for (i = 0; i < m; i++)
        {
            cin >> s1 >> s2 >> s3;
            int x, y;
            if (!mp.count(s1))
            {
                mp[s1] = proxVertice;
                x = proxVertice;
                proxVertice++;
            }
            else
                x = mp[s1];
            if (!mp.count(s2))
            {
                mp[s2] = proxVertice;
                y = proxVertice;
                proxVertice++;
            }
            else
                y = mp[s2];
            adj.resize(max(adj.size(), (size_t)(max(x, y) + 1)));
            adj[x].push_back(make_pair(y, s3));
            adj[y].push_back(make_pair(x, s3));
        }
        dijkstra();

        adj.clear();
    }
}