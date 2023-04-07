#include <bits/stdc++.h>

using namespace std;

int main()
{
    //Problema de Simulação
    //freopen("saida.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> tempo(n);
    for (int i = 0; i < n; i++)
    {
        cin >> tempo[i];
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> cliente;

    for (int i = 0; i < n; i++)
    {
        cliente.push({0, i});
    }
    int max_time = 0;
    for (int i = 0; i < m; i++)
    {
        int c;
        cin >> c;

        int end_time, id;
        tie(end_time, id) = cliente.top();

        cliente.pop();

        // O tempo total de atendimento é calculado como o valor máximo de end_time ao longo de todos os clientes.
        int time = tempo[id] * c;
        max_time = max(max_time, end_time + time);

        cliente.push({end_time + time, id});
        // A fila de prioridade é ordenada pelo valor de end_time em ordem crescente,
        // ou seja, os caixas que estarão livres mais cedo ficam no topo da fila.
    }

    cout << max_time << endl;
}