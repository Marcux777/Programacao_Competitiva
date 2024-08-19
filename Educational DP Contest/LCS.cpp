#include <bits/stdc++.h>

using namespace std;

pair<string, int> lcs(string a, string b)
{
    int n = b.size(), m = a.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    string str = "";
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            str = a[i - 1] + str;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    return {str, dp[m % 2][n]};
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << lcs(a, b).first << endl;
}