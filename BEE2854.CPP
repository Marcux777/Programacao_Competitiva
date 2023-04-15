#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 600;
vector<int> adj[MAXN];
bool visitado[MAXN];

void dfs(int u) {
    visitado[u] = true;
    for (int v : adj[u]) {
        if (!visitado[v]) {
            dfs(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    map<string, int> p;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        string nome1, nome2, rel;
        cin >> nome1 >> rel >> nome2;

        // Cria um índice único para cada pessoa
        if (p.find(nome1) == p.end()) {
            p[nome1] = ++cnt;
        }
        if (p.find(nome2) == p.end()) {
            p[nome2] = ++cnt;
        }

        // Adiciona a relação à lista de adjacência
        if (rel == "pai") {
            adj[p[nome2]].push_back(p[nome1]);
        } else if (rel == "mae") {
            adj[p[nome2]].push_back(p[nome1]);
        } else if (rel == "filho") {
            adj[p[nome1]].push_back(p[nome2]);
        } else if (rel == "filha") {
            adj[p[nome1]].push_back(p[nome2]);
        } else if (rel == "irmao") {
            adj[p[nome1]].push_back(p[nome2]);
            adj[p[nome2]].push_back(p[nome1]);
        } else if (rel == "irma") {
            adj[p[nome1]].push_back(p[nome2]);
            adj[p[nome2]].push_back(p[nome1]);
        } else if (rel == "tio") {
            adj[p[nome2]].push_back(p[nome1]);
        } else if (rel == "tia") {
            adj[p[nome2]].push_back(p[nome1]);
        } else if (rel == "primo") {
            adj[p[nome1]].push_back(p[nome2]);
            adj[p[nome2]].push_back(p[nome1]);
        } else if (rel == "prima") {
            adj[p[nome1]].push_back(p[nome2]);
            adj[p[nome2]].push_back(p[nome1]);
        }
    }

    // Marca todos os vértices alcançáveis a partir de cada pessoa
    int ans = 0;
    for (int i = 1; i <= cnt; i++) {
        if (!visitado[i]) {
            dfs(i);
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
