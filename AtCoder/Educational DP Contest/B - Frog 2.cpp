#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n), dp(n, INT_MAX);

    for (auto &i : v)
        cin >> i;

    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= i + k && j < n; j++)
        {
            int a = abs(v[i] - v[j]);
            dp[j] = min(dp[j], dp[i] + a);
        }
    }
    cout << dp[n - 1] << endl;
}