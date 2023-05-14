#include <cstdio>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;

vector<pair<int, long long int>> adjlist[510];
int vis[510];
int cid, aresta;
long long int aux;
int cont;

void dfs(int x)
{
    vis[x] = 1;
    for (int i = 0; i < (int)adjlist[x].size(); i++)
    {
        int u = adjlist[x][i].first;
        int target = adjlist[x][i].second;
        if (vis[u] == 0 && target == aux)
        {
            cont++;
            dfs(u);
        }
    }
}

int main()
{
    int a, b;
    long long int peso;
    int answer;
    while (true)
    {
        for (int i = 0; i < 510; i++)
        {
            adjlist[i].clear();
        }
        memset(vis, 0, sizeof vis);
        aux = -9999999999999; // reseta lixeira a cada caso de teste
        answer = -1;
        scanf("%d %d", &cid, &aresta);
        if (cid == 0 && aresta == 0)
        {
            break;
        }
        for (int i = 0; i < aresta; i++)
        {
            scanf("%d %d %lld", &a, &b, &peso);
            adjlist[a].push_back({b, peso});
            adjlist[b].push_back({a, peso});
            aux = max(aux, peso);
        }
        for (int i = 1; i <= cid; i++)
        {
            if (vis[i] == 0)
            {
                cont = 0;
                dfs(i);
                answer = max(answer, cont);
            }
        }
        printf("%d\n", answer + 1);
    }
}
