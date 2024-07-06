#include <bits/stdc++.h>

using namespace std;

#define int long long
#define inf LLONG_MAX

/*
Implementar:
- [] Grafo -> lista de adjacencia
    Graph traversal
        - [] DFS
        - [] BFS
    Connected components, bridges, articulations points
        - [] Finding Connected Components
        - [] Finding Bridges offline
        - [] Finding Bridges online
        - [] Finding Articulation Points
        - [] Strongly Connected Components and Condensation Graph
        - [] Strong Orientation
    Single-source shortest paths
        - [Implementado] Dijkstra:
            dijkstra() -> calcula a menor distancia de um vertice s para todos os outros
            getParents() -> retorna um vetor com os pais de cada vertice
            restore_path() -> retorna o caminho mais curto de um vertice s para um vertice t
        - [] Kruskal
        - [] Prim
        - [] Bellman-Ford
        - [] 0-1 BFS
        - [] D´Esopo-Pape
    All-pairs shortest paths
        - [] Floyd-Warshall
        - [] Number of paths of fixed length / Shortest paths of fixed length
    Spanning trees
        - [] Prim
        - [] Kruskal
        - [] Second Best Minimum Spanning Tree
        - [] Kirchhoff's theorem
        - [] Prüfer code
    Cycles
        - [] Checking a graph for acyclicity and finding a cycle in O(M)
        - [] Finding a negative cycle
        - [] Eulerian path
    Lowest common ancestor
        - [] Lowest Common Ancestor
        - [] Lowest Common Ancestor - Binary Lifting
        - [] Lowest Common Ancestor - Farach-Colton and Bender Algorithm
        - [] RMQ (Range Minimum Query) by finding LCA (Lowest Common Ancestor)
        - [] Lowest Common Ancestor - Tarjan's off-line algorithm
    Flows
        - [] Edmonds-Karp algorithm
        - [] Push-relabel algorithm
        - [] Push-relabel method improved
        - [] Dinic's algorithm
        - [] MPM algorithm
        - [] Flows with demands
        - [] Minimum-cost flow

    Matchings
        - [] Bipartite
        - [] Kuhn's Algorithm
        - [] Hungarian algorithm
    Miscellaneous
        - [] Topological Sort
        - [] Edge connectivity / Vertex connectivity
        - [] Tree painting
        - [] 2-SAT
        - [] Heavy-light decomposition
*/

class Graph
{
    int n;
    vector<vector<int>> adj;

public:
    Graph(int n)
    {
        this->n = n;
        this->adj.resize(n);
    }
    Graph(vector<vector<int>> &adj, int n)
    {
        this->n = n;
        this->adj = adj;
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }
    class Dijkstra
    {
        int n;
        vector<vector<pair<int, int>>> adj;
        vector<int> distance;
        vector<int> parent;

    public:
        Dijkstra(vector<vector<pair<int, int>>> &adj, int n)
        {
            this->n = n;
            this->adj = adj;
            this->distance = vector<int>(n, inf);
            this->parent = vector<int>(n, -1);
        }
        Dijkstra(int n)
        {
            this->n = n;
            this->adj.resize(n);
            this->distance = vector<int>(n, inf);
            this->parent = vector<int>(n, -1);
        }
        void addEdge(int u, int v, int w)
        {
            adj[u].push_back({v, w});
        }
        vector<int> dijkstra(int s)
        {
            distance[s] = 0;
            using pii = pair<int, int>;
            priority_queue<pii, vector<pii>, greater<pii>> q;
            q.push({0, s});
            while (!q.empty())
            {
                int v = q.top().second;
                int d_v = q.top().first;
                q.pop();
                if (d_v != distance[v])
                    continue;

                for (auto edge : adj[v])
                {
                    int to = edge.first;
                    int len = edge.second;

                    if (distance[v] + len < distance[to])
                    {
                        distance[to] = distance[v] + len;
                        parent[to] = v;
                        q.push({distance[to], to});
                    }
                }
            }
            return distance;
        }
        vector<int> getParents()
        {
            return parent;
        }
        vector<int> restore_path(int s, int t)
        {
            vector<int> path;
            if(parent[t] == -1) return {-1};

            for (int v = t; v != s; v = parent[v])
                path.push_back(v);
            path.push_back(s);

            reverse(path.begin(), path.end());
            return path;
        }
    };
};