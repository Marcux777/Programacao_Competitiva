# DSU (União de Conjuntos Disjuntos)
## Definição de DSU
DSU, ou "Disjoint-Set Union" em inglês, que se traduz como "União de Conjuntos Disjuntos" em português, é uma estrutura de dados que gerencia um conjunto de elementos particionados em subconjuntos disjuntos. Um conjunto disjunto é caracterizado por um conjunto de elementos que não compartilham nenhum membro em comum.

## Funcionamento do DSU
A implementação do DSU é realizada através de uma árvore. Cada nó da árvore representa um elemento do conjunto. O pai de um nó indica o conjunto ao qual o nó pertence. A raiz da árvore simboliza o conjunto disjunto representado pelo nó.

Para realizar a união de dois conjuntos, é necessário unir as raízes das árvores que representam os respectivos conjuntos. Para identificar o conjunto ao qual um elemento pertence, basta seguir o caminho do nó até a raiz da árvore.

## Aplicações do DSU
O DSU é uma estrutura de dados extremamente útil para resolver problemas que envolvem conjuntos disjuntos. Alguns exemplos de problemas que podem ser resolvidos com o uso do DSU incluem:

- Determinar o caminho mais curto entre dois pontos em um grafo.
- Identificar o número de componentes conectados em um grafo.
- Verificar se um grafo é bipartido.

**[Codigo DSU](C:\GitHub\Programacao_Competitiva\Algoritmos_Basicos\DSU\DSU.cpp)**