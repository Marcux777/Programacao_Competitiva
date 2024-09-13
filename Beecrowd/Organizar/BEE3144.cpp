#include <iostream>
#include <vector>
#include <queue>
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

    int find(int i)
    {
        if (parent[i] != i)
            parent[i] = find(parent[i]);
        return parent[i];
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
    vector<pair<int, pair<int, int>>> edgelist;
    int V;

public:
    Graph(int V) { this->V = V;}


    void addEdge(int x, int y, int w)
    {
        edgelist.push_back(make_pair(w, make_pair(x, y)));
    }

    int kruskals_mst()
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        for (auto edge : edgelist)
            pq.push(edge);

        DSU s(V);
        int ans = 0;
        while (!pq.empty())
        {
            int w = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if (s.find(x) != s.find(y))
            {
                s.unite(x, y);
                ans += w;
            }
        }
        return ans;
    }
};

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
	int d;
	scanf("%d",&d);
    Graph g(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        g.addEdge(x, y, z);
    }

    int weight = g.kruskals_mst();
    printf("%d\n", 2*weight);
    return 0;
}

