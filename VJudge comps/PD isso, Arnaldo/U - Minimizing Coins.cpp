#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define endl '\n'
#define INF INT_MAX
#define mod 1000000007

vector<int> DP;
vector<int> moedas;
int N, X;

signed main()
{
    // obter o minimo
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> X;
    moedas.resize(N);
    DP.assign(X + 1, INF);
    for (auto &i : moedas)
        cin >> i;

    sort(moedas.begin(), moedas.end());
    DP[0] = 0;
    for (int i = 1; i <= X; i++)
        for (int j = 1; j <= N; j++)
            if (i - moedas[j-1] >= 0)
                DP[i] = min(DP[i], DP[i - moedas[j-1]]+1);

    cout << (DP[X] == INF ? -1 : DP[X]) << endl;
}