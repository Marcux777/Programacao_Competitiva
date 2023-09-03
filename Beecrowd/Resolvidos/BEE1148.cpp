#include <iostream>
#include <vector>

using namespace std;

#define INF 9999999

void dijkstra(vector<vector<int>> &graph, int start, vector<int> &dist)
{
    int n = graph.size() - 1;

    vector<bool> visited(n + 1, false);

    dist[start] = 0;

    for (int i = 1; i <= n; ++i)
    {
        int u = -1, min_dist = INF;

        for (int v = 1; v <= n; ++v)
            if (!visited[v] && dist[v] < min_dist)
                min_dist = dist[v], u = v;

        if (u == -1)
            break;

        visited[u] = true;

        for (int v = 1; v <= n; ++v)
        {
            if (graph[u][v] != INF && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}

int main()
{
    // freopen("saida.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    while (cin >> n >> m && n)
    {

        vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));

        for (int i = 0; i < m; ++i)
        {
            int x, y, h;
            cin >> x >> y >> h;

            graph[x][y] = h;

            if (graph[y][x] != INF)
            {
                graph[x][y] = 0;
                graph[y][x] = 0;
            }
        }

        int k;
        cin >> k;

        for (int i = 0; i < k; ++i)
        {
            int o, d;
            cin >> o >> d;

            if (d == 0)
            {
                cout << endl;
                continue;
            }

            // Implementação do algoritmo de Dijkstra para encontrar a distância mínima entre as agências
            vector<int> dist(n + 1, INF);
            dijkstra(graph, o, dist);

            if (dist[d] == INF)
            {
                cout << "Nao e possivel entregar a carta" << endl;
            }
            else
            {
                cout << dist[d] << endl;
            }
        }
        cout << endl;
    }

    return 0;
}