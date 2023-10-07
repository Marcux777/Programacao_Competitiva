#include <iostream>
#include <vector>

using namespace std;

int countConnectedComponents(int n, vector<bool>& isdel, vector<vector<int>>& adj) {
    int ans = 0;
    vector<int> V;

    for (int k = 1; k <= n; k++) {
        if (!isdel[k]) {
            ans++;
            V.push_back(k);
            isdel[k] = true;

            for (int i = V.size() - 1; i < V.size(); i++) {
                for (int j = 0; j < adj[V[i]].size(); j++) {
                    int vertex = adj[V[i]][j];
                    if (!isdel[vertex]) {
                        isdel[vertex] = true;
                        V.push_back(vertex);
                    }
                }
            }
        }
    }

    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<bool> isdel(n + 1, false);
    vector<int> linknum(n + 1, 0);
    vector<vector<int>> adj(n + 1);
    vector<int> toDel;

    // Ler as arestas e construir a lista de adjacência
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        linknum[x]++;
        linknum[y]++;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // Identificar os vértices que não têm 2 arestas e marcá-los para exclusão
    for (int i = 1; i <= n; i++) {
        if (linknum[i] != 2) {
            toDel.push_back(i);
            isdel[i] = true;
        }
    }

    // Marcar os vértices adjacentes dos vértices marcados para exclusão
    // e adicionar esses vértices na lista de exclusão
    for (int i = 0; i < toDel.size(); i++) {
        for (int j = 0; j < adj[toDel[i]].size(); j++) {
            int vertex = adj[toDel[i]][j];
            if (!isdel[vertex]) {
                isdel[vertex] = true;
                toDel.push_back(vertex);
            }
        }
    }

    cout << countConnectedComponents(n, isdel, adj) << endl;

    return 0;
}