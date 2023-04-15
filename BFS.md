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