#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        // Criação de vetores e estruturas de dados iniciais
        vector<int> result(n, -1);                   // Vetor para armazenar as distâncias mínimas
        vector<bool> vis1(n, false), vis2(n, false); // Vetores para marcar os nós visitados
        vector<vector<pair<int, int>>> v(n);         // Lista de adjacência para representar o grafo
        queue<pair<int, int>> q;                     // Fila para a busca em largura

        // Construção do grafo a partir das arestas vermelhas
        for (auto i : redEdges)
        {
            v[i[0]].push_back({i[1], 1}); // Adiciona o nó adjacente com a aresta vermelha (valor 1)
        }

        // Construção do grafo a partir das arestas azuis
        for (auto i : blueEdges)
        {
            v[i[0]].push_back({i[1], 2}); // Adiciona o nó adjacente com a aresta azul (valor 2)
        }

        result[0] = 0;            // Define a distância do nó de origem como zero
        vis1[0] = vis2[0] = true; // Marca o nó de origem como visitado para ambas as cores (vermelho e azul)
        int aux = 1;              // Variável auxiliar para rastrear a distância

        // Propagação da busca em largura a partir do nó de origem
        for (auto i : v[0])
        {
            q.push(i); // Adiciona os nós adjacentes à fila
            if (result[i.first] == -1)
            {
                result[i.first] = aux; // Atualiza a distância mínima se ainda não estiver definida
            }
        }

        // Execução da busca em largura
        while (!q.empty())
        {
            aux++; // Incrementa a distância atual
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto valor = q.front();
                q.pop();

                if (valor.second == 1)
                {
                    vis1[valor.first] = true; // Marca o nó adjacente como visitado para a cor vermelha
                }
                else
                {
                    vis2[valor.first] = true; // Marca o nó adjacente como visitado para a cor azul
                }

                for (auto i : v[valor.first])
                {
                    if (valor.second == 1 && (vis2[i.first] || i.second == 1))
                        continue; // Se a cor da aresta atual é vermelha e o nó adjacente já foi visitado ou a aresta também é vermelha, pula para a próxima iteração
                    if (valor.second == 2 && (vis1[i.first] || i.second == 2))
                        continue; // Se a cor da aresta atual é azul e o nó adjacente já foi visitado ou a aresta também é azul, pula para a próxima iteração

                    q.push(i); // Adiciona o nó adjacente à fila

                    if (result[i.first] == -1)
                    {
                        result[i.first] = aux; // Atualiza a distância mínima se ainda não estiver definida
                    }
                }
            }
        }

        return result; // Retorna as distâncias mínimas para todos os nós do grafo
    }
};

int main()
{
    Solution solution;

    int n = 4;
    vector<vector<int>> redEdges = {{0, 1}, {1, 2}};
    vector<vector<int>> blueEdges = {{0, 3}};

    vector<int> result = solution.shortestAlternatingPaths(n, redEdges, blueEdges);

    // Imprime o resultado
    cout << "Distâncias mínimas a partir do nó de origem (0):" << endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << "Nó " << i << ": " << result[i] << endl;
    }

    return 0;
}
