#include <bits/stdc++.h>

using namespace std;

class DSU
{
    vector<int> parent;
    vector<int> rank;

public:
    int comp;
    DSU(int n)
    {
        parent.assign(n, -1);
        rank.assign(n, 1);
        comp = n;
    }

    int find(int i)
    {
        if (parent[i] == -1)
            return i;

        return parent[i] = find(parent[i]);
    }

    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
            }
            else if (rank[s1] > rank[s2])
            {
                parent[s2] = s1;
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += 1;
            }
        }
        comp--;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x > y)
            swap(x, y);
        graph[x].push_back({x, y});
    }
    DSU dsu(n + 1);
    vector<bool> vis(n + 1, false);
    for (int i = n; i >= 1; i--)
    {
        vis[i] = true;
        for (auto v : graph[i])
        {
            if (vis[v.first] || vis[v.second])
            {
                dsu.unite(v.first, v.second);
            }
        }
        cout << dsu.comp << endl;
    }
}