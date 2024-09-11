#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define inf INT_MAX
vector<int> dp;
vector<int> moedas;
int n, x;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;
    dp = vector<int>(x + 1, inf);
    moedas = vector<int>(n );

    for (auto &i : moedas)
        cin >> i;

    dp[0] = 0;

    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i - moedas[j-1] >= 0)
            {
                dp[i] = min(dp[i], dp[i - moedas[j - 1]] + 1);
            }
        }
    }
    cout << (dp[x] == inf ? -1 : dp[x]) << endl;
}