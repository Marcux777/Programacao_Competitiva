#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 1005;

char nota[MAXN];
vector<int> adj[MAXN];
bool vis[MAXN];

int bfs(int v)
{
    int cont = 0;
    queue<int> q;
    q.push(v);

    while (!q.empty())
    {
        v = q.front();
        q.pop();
        if (!vis[v])
        {
            vis[v] = true;
            if (nota[v] == 'B')
            {
                cont++;
            }
            for (int i = 0; i < (int)adj[v].size(); i++)
            {
                q.push(adj[v][i]);
            }
        }
    }
    return cont;
}

void Zera(int n)
{
    for (int i = 1; i <= n; i++)
    {
        vis[i] = false;
        adj[i].clear();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    while (cin >> n >> m)
    {
        Zera(n);
        for (int i = 1; i <= n; i++)
            cin >> nota[i];
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        bool flag = true;
        for (int i = 1; i <= n && flag; i++)
        {
            int cont;
            if (!vis[i])
            {
                cont = bfs(i);
            }
            if (cont % 2 != 0)
            {
                flag = false;
            }
        }
        cout << (flag ? 'Y' : 'N') << endl;
    }
    return 0;
}
