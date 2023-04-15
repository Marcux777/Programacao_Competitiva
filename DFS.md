# DFS - Depth-First Search

DFS (Depth-First Search) é um algoritmo de busca em grafos que percorre todos os vértices de um grafo de forma recursiva, visitando primeiro um vértice e, em seguida, explorando ao máximo cada um dos seus vizinhos antes de voltar e visitar o próximo vértice não visitado. O algoritmo é chamado "depth-first" porque ele explora até o máximo possível em cada ramificação antes de fazer backtracking e explorar outras ramificações em profundidade.

Para uma árvore, a DFS é uma busca recursiva que percorre todos os nós da árvore em profundidade, visitando primeiro a raiz, em seguida, recursivamente visitando os filhos da raiz, depois os filhos dos filhos e assim por diante. Quando a busca encontra um nó sem filhos, a busca volta para o nó pai e continua explorando outros ramos da árvore.

Para um grafo, a DFS é um pouco mais complexa, pois pode haver ciclos no grafo. Nesse caso, é preciso marcar cada vértice visitado para garantir que o algoritmo não fique preso em um ciclo infinito. A DFS começa visitando um vértice inicial e marca-o como visitado. Em seguida, ela chama recursivamente a DFS para todos os vértices adjacentes que ainda não foram visitados. Esse processo é repetido até que todos os vértices tenham sido visitados. Se a DFS encontrar um vértice já visitado, ela volta para o vértice anterior e continua explorando outros ramos do grafo.

# DFS para Árvores

Existem três formas de percorrer uma árvore com DFS:

## Pré-ordem (Pre-Order):
Nesta forma de percorrer a árvore, primeiro visita-se o nó raiz e, em seguida, visita-se recursivamente seus filhos da esquerda para a direita. Dessa forma, a ordem de visitação dos nós é sempre raiz, subárvore esquerda e subárvore direita.

```C++
    void preOrder(Node* root) {
        if (root == NULL){
            return;
        }

        // Visita o nó atual
        cout << root->data << " ";

        // Percorre a subárvore esquerda
        preOrder(root->left);

        // Percorre a subárvore direita
        preOrder(root->right);
    }
```

## Pós-ordem (post-order):
Nesta forma de percorrer a árvore, primeiro visita-se recursivamente os filhos da esquerda para a direita e, em seguida, visita-se o nó raiz. Dessa forma, a ordem de visitação dos nós é sempre subárvore esquerda, subárvore direita e raiz.

```C++
    void posOrder(Node* root) {
        if (root == NULL) {
            return;
        }

        // Percorre a subárvore esquerda
        posOrder(root->left);

        // Percorre a subárvore direita
        posOrder(root->right);

        // Visita o nó atual
        cout << root->val << " ";
    }
```

## Em-ordem (in-order): 
Esta forma de percorrer a árvore é aplicável apenas em árvores binárias. Neste método, primeiro visita-se recursivamente o filho da esquerda, em seguida visita-se o nó raiz e, finalmente, visita-se recursivamente o filho da direita. Dessa forma, a ordem de visitação dos nós é sempre subárvore esquerda, raiz e subárvore direita.

```C++
    void inOrder(Node* root) {
        if(root == NULL){
            return;
        }

        // Percorre a subárvore esquerda
        inOrder(root->left);

        // Visita o nó atual
        cout << root->val << " ";

        // Percorre a subárvore direita
        inOrder(root->right);
    }
```

# DFS para Grafos

A DFS (Depth-First Search) em grafos é um algoritmo de busca em profundidade que visita todos os vértices do grafo. A DFS é implementada de forma recursiva, visitando um vértice de cada vez e explorando o máximo possível antes de retroceder.

```C++
    #include <iostream>
    #include <vector>

    using namespace std;

    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int v) {
        visited[v] = true; // Marca o vértice atual como visitado
        cout << v << " "; // Imprime o vértice atual

        for (int i = 0; i < graph[v].size(); i++) {
            int neighbor = graph[v][i]; // Obtém o vizinho atual do vértice
            if (!visited[neighbor]) { // Verifica se o vizinho ainda não foi visitado
                dfs(graph, visited, neighbor); // Chama a função dfs recursivamente para o vizinho
            }
        }
    }

    int main() {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> graph(n); // Cria um vetor de vetores para representar o grafo

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v); // Adiciona a aresta u -> v no grafo
            graph[v].push_back(u); // Adiciona a aresta v -> u no grafo (caso o grafo seja não-direcionado)
        }

        vector<bool> visited(n, false); // Cria um vetor para marcar quais vértices já foram visitados

        for (int i = 0; i < n; i++) {
            if (!visited[i]) { // Verifica se o vértice i ainda não foi visitado
                dfs(graph, visited, i); // Chama a função dfs para o vértice i
            }
        }

        return 0;
    }
```
