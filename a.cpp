#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int o, d, k;
    while (cin >> o >> d >> k && (o || d || k))
    {
        vector<int> v(200000, 0);
        for (int i = 0, a; i < k; i++)
        {
            cin >> a;
            v[a] = 1;
        }

        queue<int> q;
        vector<int> dist(200000, -1);
        q.push(o);
        dist[o] = 0;
        while (!q.empty())
        {
            if (dist[d] != -1)
                break;
            int u = q.front();
            q.pop();
            if (!v[u - 1] && u - 1 > 0 && dist[u - 1] == -1)
            {
                dist[u - 1] = dist[u] + 1;
                q.push(u - 1);
            }
            if (!v[u + 1] && u + 1 <= 100000 && dist[u + 1] == -1)
            {
                dist[u + 1] = dist[u] + 1;
                q.push(u + 1);
            }
            if (u % 2 == 0 && !v[u / 2] && dist[u / 2] == -1)
            {
                dist[u / 2] = dist[u] + 1;
                q.push(u / 2);
            }
            if (u * 2 <= 100000 && !v[u * 2] && dist[u * 2] == -1)
            {
                dist[u * 2] = dist[u] + 1;
                q.push(u * 2);
            }
            if (u * 3 <= 100000 && !v[u * 3] && dist[u * 3] == -1)
            {
                dist[u * 3] = dist[u] + 1;
                q.push(u * 3);
            }
        }
        cout << dist[d] << endl;
    }
}
