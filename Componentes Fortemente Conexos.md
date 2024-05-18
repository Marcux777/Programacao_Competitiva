# Encontrando Componentes Fortemente Conexos / Construindo o Grafo de Condensação
Este documento descreve como encontrar componentes fortemente conexos (CFCs) em um grafo direcionado e construir o grafo de condensação.

## Componentes Fortemente Conexos
Um componente fortemente conexo (CFC) é um subgrafo máximo no qual cada par de vértices é alcançável um do outro. Em outras palavras, para quaisquer dois vértices em um CFC, existe um caminho direcionado de um para o outro.

## Encontrando CFCs
Existem vários algoritmos para encontrar CFCs em um grafo direcionado. Um dos algoritmos mais comuns é o algoritmo de Kosaraju, que consiste em duas fases:

- Inverter o grafo: Crie um novo grafo invertendo a direção de todas as arestas no grafo original.
- Realize duas travessias DFS:
  - Realize uma travessia DFS no grafo invertido, começando por qualquer vértice não visitado.
  - Para cada vértice visitado na primeira DFS, realize uma travessia DFS no grafo original, começando por esse vértice.
Os vértices visitados na segunda travessia DFS formam um CFC. Repetindo este processo para todos os vértices não visitados na primeira DFS, podemos encontrar todos os CFCs no grafo.

## Construindo o Grafo de Condensação
O grafo de condensação é um grafo acíclico direcionado (DAG) que representa os CFCs do grafo original. Os vértices do grafo de condensação são os CFCs, e existe uma aresta do CFC A para o CFC B se houver uma aresta de um vértice em A para um vértice em B no grafo original.

Para construir o grafo de condensação, podemos usar as seguintes etapas:

Crie um novo grafo com um vértice para cada CFC.
Para cada aresta no grafo original, adicione uma aresta do CFC contendo a cauda da aresta para o CFC contendo a cabeça da aresta.