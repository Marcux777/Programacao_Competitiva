# Componentes Conexos

Este é um algoritmo em C++ que utiliza a técnica de Busca em Profundidade (DFS - Depth-First Search) para encontrar componentes conexos em um grafo.

```cpp
#include <bits/stdc++.h>
using namespace std;

int n; // Número de nós no grafo
vector<vector<int>> adj; // Lista de adjacência que representa o grafo
vector<bool> used; // Vetor para marcar os nós que já foram visitados
vector<int> comp; // Vetor para armazenar os nós do componente atual
```

Aqui, `n` é o número de nós no grafo. `adj` é uma lista de adjacência que representa o grafo. `used` é um vetor booleano que marca os nós que já foram visitados. `comp` é um vetor que armazena os nós do componente atual.

```cpp
void dfs(int v) {
    used[v] = true;
    comp.push_back(v);
    for (int u : adj[v]) {
        if (!used[u])
            dfs(u);
    }
}
```

A função `dfs` realiza uma busca em profundidade a partir do nó `v`. Ela marca o nó `v` como visitado, adiciona `v` ao componente atual e, em seguida, visita todos os vizinhos `u` de `v` que ainda não foram visitados.

```cpp
void find_comps() {
    fill(used.begin(), used.end(), 0);
    for (int v = 0; v < n; ++v) {
        if (!used[v]) {
            comp.clear();
            dfs(v);
            cout << "Component:";
            for (int u : comp)
                cout << ' ' << u;
            cout << endl;
        }
    }
}
```

A função `find_comps` encontra todos os componentes conexos do grafo. Ela itera sobre todos os nós do grafo e, para cada nó não visitado, realiza uma busca em profundidade para encontrar o componente conexo desse nó. Em seguida, imprime todos os nós desse componente.

**[CODIGO](./Algoritmos_Basicos/Grafos/Connected%20components,%20bridges,%20articulations%20points/Finding%20Connected%20Components.cpp)**