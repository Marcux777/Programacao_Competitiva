#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <vector>
using namespace std;

const int MAXN = 210;
int N, M;
vector<string> prov[MAXN];  // vetor de aplicativos para cada servidor
vector<string> user[MAXN];  // vetor de aplicativos para cada usuário
map<string, set<int>> apps; // mapa de aplicativos para o conjunto de servidores que possuem o aplicativo

int main()
{
    //freopen("saida.txt", "w", stdout);
    while (scanf("%d%d", &N, &M)&& N && M)
    {
        apps.clear();

        // Lê os aplicativos para cada servidor
        for (int i = 1; i <= N; i++)
        {
            int Qi;
            scanf("%d", &Qi);
            prov[i].clear();
            for (int j = 0; j < Qi; j++)
            {
                string app;
                cin >> app;
                prov[i].push_back(app);
                apps[app].insert(i);
            }
        }

        // Lê os aplicativos para cada usuário
        for (int i = 1; i <= M; i++)
        {
            int Pj;
            scanf("%d", &Pj);
            user[i].clear();
            for (int j = 0; j < Pj; j++)
            {
                string app;
                cin >> app;
                user[i].push_back(app);
            }
        }

        // Calcula a resposta para cada usuário
        int ans = 0;
        for (int i = 1; i <= M; i++)
        {
            set<int> servers;
            for (int j = 0; j < (int)user[i].size(); j++)
            {
                string app = user[i][j];
                set<int> candidates = apps[app];
                servers.insert(candidates.begin(), candidates.end());
            }
            ans += servers.size();
        }

        // Imprime a resposta para esse caso de teste
        printf("%d\n", ans);
    }

    return 0;
}
