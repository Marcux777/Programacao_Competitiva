#include <bits/stdc++.h>

using namespace std;

class DSU
{
    vector<int> parent;
    vector<int> rank;
    vector<int> order; // obter a ordem (tamanho) do conjunto ao qual um elemento pertence

public:
    DSU(int n)
    {
        parent.resize(n, -1);
        rank.resize(n, 0);
        order.resize(n, 1);
    }
    int ordem(int x)
    {
        return order[find(x)];
    }

    int find(int i)
    {
        if (parent[i] == -1)
            return i;

        return parent[i] = find(parent[i]);
    }

    bool connected(int x, int y)
    { // se os elementos pertencem ao msm conjunto
        return find(x) == find(y);
    }

    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
                swap(s1, s2);
            parent[s2] = s1;
            if (rank[s1] == rank[s2])
                rank[s1]++;
            order[s1] += order[s2];
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
    vector<int> u(m);
    vector<int> v(m);
    DSU dsu(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        u[i] = x - 1;
        v[i] = y - 1;
    }
    for (int i = 0; i < m; i++)
    {
        if (!dsu.connected(u[i], v[i]))
        {
            dsu.unite(u[i], v[i]);
        }
    }
    vector<int> cont(n);
    for (int i = 0; i < m; i++)
    {
        int id = dsu.find(u[i]);
        cont[id]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (dsu.find(i) == i)
        {

            if (dsu.ordem(i) != cont[i])
            {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
}