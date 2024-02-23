/*
Um consórcio de provedores de internet europeus gerencia uma grande rede principal, com conexões diretas entre um grande número
de cidades europeias. Uma conexão entre um par de cidades é bidirecional.
A transmissão de uma mensagem em uma conexão tem um custo associado. Como é comum na Internet,
é possível usar uma sequência (ilimitada) de conexões diretas para transferir dados indiretamente entre qualquer par de cidades.
Para permitir a transmissão de programas de TV usando essa rede principal,
é necessário enviar continuamente dados para todos os nós da rede. Para ajudar a minimizar os custos,
é necessário selecionar as conexões de rede que serão usadas para transmitir dados. O conjunto de conexões selecionadas deve
ser conectado e incluir todos os nós da rede.
Para ajudar o consórcio a gerenciar sua rede, foi solicitado que você criasse um programa que calcula o
custo mínimo para transmitir dados para todas as cidades da rede principal.
Dado um conjunto de conexões de rede, calcule o custo mínimo de transmissão para alcançar todos os nós.
Entrada
A entrada consiste em vários casos de teste. A primeira linha da entrada contém o número de casos de teste.
Há uma linha em branco antes de cada conjunto de dados.
A primeira linha de cada conjunto de dados contém um inteiro positivo M, não maior que 2.000, com o
número de cidades que têm conexões de rede. A segunda linha contém um inteiro N não maior que 50.000,
com o número de conexões existentes. Cada uma das N linhas seguintes contém a representação de uma conexão.
Cada linha contém duas strings e um inteiro, separados por espaços vazios, B E C, onde B e E são os nomes das cidades
nos extremos da conexão de rede, com no máximo 8 caracteres, e C é um inteiro positivo, não maior que 30, representando o
custo de transmissão na conexão.
Saída
Para cada caso de teste, a saída consiste em uma única linha que contém um inteiro com o custo mínimo
de transmissão para enviar dados para todas as cidades.
Imprima uma linha em branco entre os conjuntos de dados.

*/

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

map<string, int> mp;

pair<int, int> id(string c1, string c2)
{
    int a, b;
    if (mp.find(c1) != mp.end())
    {
        a = mp[c1];
    }
    else
    {
        mp[c1] = mp.size();
    }
    a = mp[c1];
    if (mp.find(c2) != mp.end())
    {
        b = mp[c2];
    }
    else
    {
        mp[c2] = mp.size();
    }
    b = mp[c2];
    return {a, b};
}

class DSU
{
    int *parent;
    int *rank;

public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    // Find function
    int find(int i)
    {
        if (parent[i] == -1)
            return i;

        return parent[i] = find(parent[i]);
    }

    // Union function
    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
            }
            else if (rank[s1] > rank[s2])
            {
                parent[s2] = s1;
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += 1;
            }
        }
    }
};

class Graph
{
    vector<vector<int>> edgelist;
    int V;

public:
    Graph(int V) { this->V = V; }

    // Function to add edge in a graph
    void addEdge(int x, int y, int w)
    {
        edgelist.push_back({w, x, y});
    }

    void kruskals_mst()
    {
        // Sort all edges
        sort(edgelist.begin(), edgelist.end());

        // Initialize the DSU
        DSU s(V);
        int ans = 0;

        for (auto edge : edgelist)
        {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            // Take this edge in MST if it does
            // not forms a cycle
            if (s.find(x) != s.find(y))
            {
                s.unite(x, y);
                ans += w;
            }
        }
        cout << ans << endl;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, m, n, peso;
    cin >> t;
    string c1, c2;

    while (t--)
    {
        cin >> m >> n;
        Graph g(m + 1);
        for (int i = 0; i < n; i++)
        {
            cin >> c1 >> c2 >> peso;
            auto p = id(c1, c2);
            // cout << p.first << " " << p.second << endl;
            g.addEdge(p.first, p.second, peso);
        }
        g.kruskals_mst();
        mp.clear();
        if (t > 0)
            cout << endl;
    }
}