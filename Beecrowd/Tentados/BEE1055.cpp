#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int Soma(const std::vector<int> &nums)
{
    int sum = 0;
    for (int i = 1; i < nums.size(); ++i)
    {
        sum += abs(nums[i] - nums[i - 1]);
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("saida.txt", "w", stdout);

    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int par = 0;
        int impar = 1;
        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = 1; i < n; i++)
        {
            dp[i][0] += abs(v[i] - v[i - 1]);
        }

        for (int i = 2; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + abs(v[i] - v[i - 1]);
            }
        }

        int soma = 0;
        for (int i = 0; i < n; i++)
        {
            soma = max(soma, dp[n - 1][i]);
        }

        cout << "Case " << j + 1 << ": " << soma << endl;
    }
}