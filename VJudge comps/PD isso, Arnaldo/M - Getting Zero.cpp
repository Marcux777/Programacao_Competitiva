#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define endl '\n'
#define INF LLONG_MAX
#define mod 32768

int N;

vector<int> precalculate()
{
    vector<int> dp(mod + 1, mod);
    dp[mod] = 0;
    for (int v = mod; v >= 0; v--)
        for (int i = 0; i <= 20; i++)
            for (int j = 0; j <= 20; j++)
                if (((v + i) << j) % mod == 0)
                    dp[v] = min(dp[v], i + j);

    return dp;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    vector<int> DP = precalculate();
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        cout << DP[x] << " ";
    }
    cout << endl;
}