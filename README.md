# Programação Competitiva

Este repositório contém conteúdo relacionado à programação competitiva, como algoritmos e estruturas de dados comumente usados.

## Meus Perfis

1. <a href="https://www.beecrowd.com.br/judge/pt/profile/542742" target="_blank" rel="noopener noreferrer">Beecrowd</a> - Plataforma brasileira de treinamento em programação competitiva.
2. <a href="https://leetcode.com/Marcux777/" target="_blank" rel="noopener noreferrer">LeetCode</a> - Site com desafios de programação e entrevistas.
3. <a href="https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=15" target="_blank" rel="noopener noreferrer">UVa Online Judge</a> - Site com uma ampla variedade de problemas de programação competitiva.


## Sumário

### Grafos

1. [BFS](README.md#bfs---breadth-first-search)

    * [BFS para Árvores](README.md#bfs-para-árvores)
    * [BFS para Grafos](README.md#bfs-para-árvores)
   
2. [DFS](README.md#dfs---depth-first-search)

   * [DFS para Árvores](README.md#dfs-para-árvores)
 
      - [Pré-ordem (Pre-Order)](README.md#pré-ordem-pre-order)
      
      - [Pós-ordem (post-order)](README.md#pós-ordem-post-order)
      
      - [Em-ordem (in-order)](README.md#em-ordem-in-order)
      
   * [DFS para Grafos](README.md#dfs-para-grafos)


# BFS - Breadth First Search

A busca em largura (BFS - Breadth-First Search) é um algoritmo utilizado para percorrer árvores ou grafos em busca de um nó que atenda a determinados critérios. Ele começa pela raiz da estrutura e visita todos os nós no nível atual antes de avançar para os nós no próximo nível. A BFS é útil para determinar o nível de cada nó a partir de um nó de origem dado.

O algoritmo da BFS utiliza uma fila para armazenar os nós a serem visitados. O processo começa com a inserção do nó raiz na fila. Enquanto a fila não estiver vazia, o primeiro nó da fila é removido e seus filhos são visitados. Os filhos visitados são adicionados à fila para serem processados posteriormente. Esse processo é repetido até que a fila esteja vazia, indicando que todos os nós foram visitados. A BFS é uma técnica eficiente para solucionar problemas na teoria dos grafos.

# BFS para Árvores

A BFS em árvores é uma técnica simples e útil para percorrer árvores em largura. Ela começa do nó raiz e visita todos os nós em um nível antes de passar para o próximo nível. A BFS pode ser usada para encontrar um nó específico ou buscar informações relevantes na árvore.

O algoritmo da BFS em árvores usa uma fila para armazenar os nós a serem visitados. Começa com a inserção do nó raiz na fila. Enquanto a fila não estiver vazia, o primeiro nó da fila é removido e seus filhos são visitados. Os filhos visitados são adicionados à fila para serem processados posteriormente. Esse processo é repetido até que a fila esteja vazia, indicando que todos os nós foram visitados.

Em resumo, a BFS em árvores é uma técnica eficiente para percorrer árvores em largura e pode ser usada para encontrar um nó específico ou buscar informações relevantes na árvore.

```C++
    //Exemplo de código BFS em árvores
    #include <iostream>
    #include <queue>

    using namespace std;

    // Definindo a estrutura de um nó da árvore
    struct Node {
        int value;
        Node *left;
        Node *right;

        Node(int v) {
            value = v;
            left = right = NULL;
        }
    };

    // Função que percorre a árvore em largura
    void bfs(Node *root) {
        if (root == NULL) return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node *curr = q.front();
            q.pop();

            cout << curr->value << " ";

            if (curr->left != NULL) {
                q.push(curr->left);
            }

            if (curr->right != NULL) {
                q.push(curr->right);
            }
        }
    }

    // Exemplo de uso
    int main() {
        Node *root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->left = new Node(4);
        root->left->right = new Node(5);
        root->right->left = new Node(6);
        root->right->right = new Node(7);

        cout << "BFS traversal: ";
        bfs(root);

        return 0;
    }

```

# BFS para Grafos

A busca em largura (BFS) também pode ser usada para percorrer grafos. Para isso, precisamos representar o grafo em uma estrutura de dados adequada, como uma lista de adjacências. A BFS começa em um vértice raiz e explora todos os vértices vizinhos antes de continuar para os vértices de nível mais profundo.

```C++
    #include <iostream>
    #include <vector>
    #include <queue>

    using namespace std;

    // representação do grafo por lista de adjacências
    vector<int> adj[100];

    void bfs(int root) {
        queue<int> q;
        vector<bool> visited(100, false); // marca os vértices já visitados
        q.push(root);
        visited[root] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cout << curr << " "; // imprime o vértice visitado

            // adiciona os vértices vizinhos não visitados na fila
            for (int i = 0; i < adj[curr].size(); i++) {
                int neighbor = adj[curr][i];
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

    int main() {
        // exemplo de grafo com 6 vértices e 7 arestas
        adj[1].push_back(2);
        adj[1].push_back(3);
        adj[2].push_back(4);
        adj[2].push_back(5);
        adj[3].push_back(5);
        adj[4].push_back(6);
        adj[5].push_back(6);

        bfs(1); // chama a bfs com o vértice 1 como raiz

        return 0;
    }
```
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


