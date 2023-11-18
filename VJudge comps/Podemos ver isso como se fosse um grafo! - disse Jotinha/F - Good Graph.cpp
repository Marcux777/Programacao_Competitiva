#include <bits/stdc++.h>

using namespace std;

#define pii pair<long long, long long>

class DSU
{
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n)
    {
        parent.assign(n, -1);
        rank.assign(n, 1);
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
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    DSU dsu(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        dsu.unite(a, b);
    }
    int k;
    cin >> k;
    map<pii, bool>edges;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        x = dsu.find(x);
        y = dsu.find(y);
        edges[{x, y}] = true;
        edges[{y, x}] = true;
    }
    int q;
    cin >> q;

    for (int j = 0; j < q; j++)
    {
        int x, y;
        cin >> x >> y;
        pii p = {dsu.find(x), dsu.find(y)};
        if(edges[{p.first, p.second}] || edges[{p.second, p.first}]){
            cout << "No\n";
        }else{
            cout << "Yes\n";
        }
    }
}