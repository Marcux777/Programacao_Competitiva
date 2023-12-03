#include <bits/stdc++.h>
using namespace std;

#define mod 998244353
#define endl '\n'
#define int long long int
int N;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;

    vector<int> a(N);
    for (auto &i : a)
        cin >> i;

    int ans = 0;
    vector<vector<vector<int>>> dp;

    for (int i = 1; i <= N; i++)
    {
        dp.assign(N + 1, vector<vector<int>>(i + 1, vector<int>(i, 0)));
        dp[0][0][0] = 1;
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k <= i; k++)
            {
                for (int l = 0; l < i; l++)
                {
                    dp[j + 1][k][l] += dp[j][k][l];
                    dp[j + 1][k][l] %= mod;
                    if (k != i)
                    {
                        dp[j + 1][k + 1][(l + a[j]) % i] += dp[j][k][l];
                        dp[j + 1][k + 1][(l + a[j]) % i] %= mod;
                    }
                }
            }
        }
        ans += dp[N][i][0];
        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}
