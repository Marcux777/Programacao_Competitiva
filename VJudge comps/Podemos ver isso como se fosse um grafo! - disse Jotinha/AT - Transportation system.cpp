#include <bits/stdc++.h>

using namespace std;

#define int long long int

class DSU
{
    int *parent;
    int *rank;

public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
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

class Graph
{
    vector<vector<int>> edgelist;
    int V;
    int r;

public:
    Graph(int V, int r)
    {
        this->V = V;
        this->r = r;
    }
    void addEdge(int x, int y, int w)
    {
        edgelist.push_back({w, x, y});
    }

    vector<double> kruskals_mst()
    {
        sort(edgelist.begin(), edgelist.end());

        DSU s(V);
        double rail = 0;
        double road = 0;
        double estado = 1;
        for (auto edge : edgelist)
        {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            if (s.find(x) != s.find(y))
            {
                s.unite(x, y);
                if (w > r * r)
                {
                    rail += sqrt(w);
                    estado++;
                }
                else
                {
                    road += sqrt(w);
                }
            }
        }
        return {road, rail, estado};
    }
};

int dist(pair<int, int> a, pair<int, int> b)
{
    return ((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

signed main()
{
    ios_base::sync_with_stdio(true);
    cin.tie(0);
    cout.tie(0);
    // freopen("saida.txt", "w", stdout);
    int t, caso = 0;
    cin >> t;
    while (t--)
    {
        int n, r;
        cin >> n >> r;
        vector<pair<int, int>> cidades(n);
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            cidades[i] = {x, y};
        }
        Graph graph(n, r);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                int w = dist(cidades[i], cidades[j]);
                graph.addEdge(i, j, w);
            }
        }
        cout << fixed << setprecision(0);
        cout << "Case #" << ++caso << ": ";
        vector<double> c = graph.kruskals_mst();
        cout << c[2] << " ";
        cout << c[0] << " " << c[1] << endl;
    }
}