/*

Para atrair mais visitantes, o gerente de um parque nacional teve a ideia de plantar flores ao longo dos dois
lados das trilhas populares, que são as trilhas usadas pelas pessoas comuns.
As pessoas comuns só vão da entrada do parque ao seu pico mais alto, onde as vistas são de tirar o fôlego,
pelo caminho mais curto. Então, ele quer saber quantos metros de flores são necessários para materializar sua ideia.

Por exemplo, no parque cujo mapa é mostrado na figura, as pessoas comuns fazem apenas um dos três seguintes
caminhos (que são os caminhos mais curtos da entrada ao pico mais alto).
• Na entrada, alguns começam na trilha mais à direita para chegar ao ponto de interesse 3 (após 100 metros),
seguem diretamente para o ponto 7 (200 metros) e depois pegam a trilha direta para o pico mais alto (620 metros).
• Os outros vão para a esquerda na entrada e chegam ao ponto 1 (após 580 metros). Então, eles pegam uma das duas
trilhas que levam ao ponto 4 (ambas têm 90 metros). No ponto 4, eles seguem a trilha direta para o pico mais alto (250 metros).

Observe que as trilhas populares (ou seja, as trilhas seguidas pelas pessoas comuns) são destacadas em amarelo.
Como a soma de seus comprimentos é de 1930 metros, a extensão de flores necessária para cobrir os dois lados das trilhas
populares é de 3860 metros (3860 = 2 × 1930).

Dada uma descrição do parque, com seus pontos de interesse e trilhas (de duas vias),
o objetivo é descobrir a extensão de flores necessária para cobrir os dois lados das trilhas populares.
É garantido que, para as entradas dadas, existe algum caminho da entrada do parque até o pico mais alto.

Entrada
O arquivo de entrada contém vários casos de teste, cada um deles conforme descrito abaixo.
A primeira linha da entrada tem dois inteiros: P e T. P é o número de pontos de interesse e
T é o número de trilhas. Os pontos são identificados por inteiros, variando de 0 a P - 1.
O ponto de entrada é 0 e o pico mais alto é o ponto P - 1.
Cada uma das seguintes linhas T caracteriza uma trilha diferente.
Contém três inteiros, p1, p2 e l, que indicam que a trilha (de duas vias) liga diretamente os
pontos p1 e p2 (não necessariamente distintos) e tem comprimento l (em metros).
Os inteiros na mesma linha são separados por um único espaço.
Restrições:
2 ≤ P ≤ 10 000 Número de pontos.
1 ≤ T ≤ 250 000 Número de trilhas.
1 ≤ l ≤ 1 000 Comprimento de uma trilha.

Saída
Para cada caso de teste, a saída tem uma única linha com a extensão de flores (em metros) necessária para cobrir os
dois lados das trilhas populares.*/

#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000000;

vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> &d, vector<int> &p)
{
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> u(n, false);

    d[s] = 0;
    for (int i = 0; i < n; i++)
    {
        int v = -1;
        for (int j = 0; j < n; j++)
        {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        if (d[v] == INF)
            break;

        u[v] = true;
        for (auto edge : adj[v])
        {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to])
            {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
    cout << d[n - 1] << endl;
}

int main()
{
    int n, t;
    cin >> n >> t;
    adj = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());

    for (int i = 0; i < t; i++)
    {
        int x, y, peso;
        cin >> x >> y >> peso;
        adj[x].push_back({y, peso});
        adj[y].push_back({x, peso});
    }
    vector<int> dist, parents;
    dijkstra(0, dist, parents);
}