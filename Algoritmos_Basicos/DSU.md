# DSU (União de Conjuntos Disjuntos)
## Definição de DSU
DSU, ou "Disjoint-Set Union" ou simplesmente Union-Find, é uma estrutura de dados que gerencia um conjunto de elementos particionados em subconjuntos disjuntos. Um conjunto disjunto é caracterizado por um conjunto de elementos que não compartilham nenhum membro em comum.

## Funcionamento do DSU
A implementação do DSU é realizada através de uma árvore. Cada nó da árvore representa um elemento do conjunto. O pai de um nó indica o conjunto ao qual o nó pertence. A raiz da árvore simboliza o conjunto disjunto representado pelo nó.

Para realizar a união de dois conjuntos, é necessário unir as raízes das árvores que representam os respectivos conjuntos. Para identificar o conjunto ao qual um elemento pertence, basta seguir o caminho do nó até a raiz da árvore.

## Aplicações do DSU
O DSU é uma estrutura de dados extremamente útil para resolver problemas que envolvem conjuntos disjuntos. Alguns exemplos de problemas que podem ser resolvidos com o uso do DSU incluem:

- Determinar o caminho mais curto entre dois pontos em um grafo.
- Identificar o número de componentes conectados em um grafo.
- Verificar se um grafo é bipartido.

## Complexidade

A complexidade da operação find é quase constante, O(α(n)), onde α(n) é a função inversa de Ackermann, que cresce extremamente lentamente. A complexidade da operação unite é O(1) em média.

**[CODIGO DSU](./Algoritmos_Basicos/Estrutura%20de%20Dados/DSU/DSU.cpp)**