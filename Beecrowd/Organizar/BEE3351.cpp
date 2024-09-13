#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

bool isPossible(ll N, ll K, vector<pair<ll, ll>> &viewers, ll moment)
{
    /* verifica se é possível atingir K ou mais visualizações até um determinado momento. 
    A função percorre todos os visualizadores, calcula o número de visualizações 
    que ocorreriam até o momento fornecido e verifica se o total de visualizações é maior ou igual a K. 
    Se for o caso, retorna true, caso contrário, retorna false.*/
    ll totalViews = 0;

    for (int i = 0; i < N; i++)
    {
        ll PrimView = viewers[i].first;
        ll Intervalo = viewers[i].second;

        ll ViewsAux = max(0LL, (moment - PrimView) / Intervalo + 1);
        totalViews += ViewsAux;

        if (totalViews >= K)
        {
            return true;
        }
    }

    return false;
}

ll Busca_Binaria(ll N, ll K, vector<pair<ll, ll>> &viewers)
{
    ll l = 0;
    ll r = 2e18;
    ll result = r;

    while (l <= r)
    {
        ll mid = l + (r - l) / 2;

        if (isPossible(N, K, viewers, mid))
        {
            result = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, K;
    cin >> N >> K;

    vector<pair<ll, ll>> viewers(N);
    for (int i = 0; i < N; i++)
    {
        ll PrimView, Intervalo;
        cin >> PrimView >> Intervalo;
        viewers[i] = {PrimView, Intervalo};
    }

    ll firstMoment = Busca_Binaria(N, K, viewers);

    cout << firstMoment << endl;

    return 0;
}
