#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define inf LLONG_MAX
#define Ninf LLONG_MIN
#define mod 1000000007

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K;
    cin >> N >> K;

    vector<int> C(N), V(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> C[i] >> V[i];
    }

    vector<vector<long long>> dp(N, vector<long long>(2, 0));
    dp[0][1] = V[0];

    for (int i = 1; i < N; ++i)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = max(dp[i - 1][0] + V[i], dp[i - 1][1]);
    }

    long long answer = max(dp[N - 1][0], dp[N - 1][1]);
    cout << answer << endl;
}