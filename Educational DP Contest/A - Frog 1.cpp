#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define inf LLONG_MAX
vector<int> dp;

signed main()
{
    int n;
    cin >> n;
    dp.assign(n, inf);
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;

    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        if (i + 1 < n)
            dp[i + 1] = min(dp[i + 1], dp[i] + abs(v[i] - v[i + 1]));
        if (i + 2 < n)
            dp[i + 2] = min(dp[i + 2], dp[i] + abs(v[i] - v[i + 2]));
    }
    cout << dp[n-1] << endl;
}