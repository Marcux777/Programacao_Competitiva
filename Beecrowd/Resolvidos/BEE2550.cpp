#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
            parent[i] = i;
            rank[i] = 1;
        }
    }

    // Find function with path compression
    int find(int i)
    {
        if (parent[i] != i)
            parent[i] = find(parent[i]);
        return parent[i];
    }

    // Union function by rank
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
    vector<pair<int, pair<int, int>>> edgelist;
    int V;
    int conjunto;

public:
    Graph(int V) { this->V = V; conjunto = V-1;}

    int getConjunto(){
        return conjunto;
    }
    // Function to add edge in a graph
    void addEdge(int x, int y, int w)
    {
        edgelist.push_back(make_pair(w, make_pair(x, y)));
    }

    int kruskals_mst()
    {
        // Sort all edges
        sort(edgelist.begin(), edgelist.end());

        // Initialize the DSU
        DSU s(V);
        int ans = 0;
        for (auto edge : edgelist)
        {
            int w = edge.first;
            int x = edge.second.first;
            int y = edge.second.second;

            // Take this edge in MST if it does
            // not form a cycle
            if (s.find(x) != s.find(y))
            {
                s.unite(x, y);
                this->conjunto--;
                ans += w;
            }
        }
        return ans;
    }
};

int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        Graph g(n + 1);
        for (int i = 0; i < m; i++)
        {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            g.addEdge(x, y, z);
        }

        
        int weight = g.kruskals_mst();
        if (g.getConjunto() == 1)
        {
            printf("%d\n", weight);
        }
        else
        {
            printf("impossivel\n");
        }
    }
    return 0;
}
