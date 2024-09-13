#include <bits/stdc++.h>

using namespace std;

vector<int> tempo, pont;
vector<vector<int>> dp;
int n, t;

int unboundedKnapsack(int W)
{
    // Stores most dense item
    int maxDenseIndex = 0;

    // Find the item with highest unit value
    // (if two items have same unit value then choose the
    // lighter item)
    for (int i = 1; i < pont.size(); i++)
    {
        if (pont[i] / tempo[i] > pont[maxDenseIndex] / tempo[maxDenseIndex] || (pont[i] / tempo[i] == pont[maxDenseIndex] / tempo[maxDenseIndex] && tempo[i] < tempo[maxDenseIndex]))
        {
            maxDenseIndex = i;
        }
    }

    int dp[W + 1] = {0};

    int counter = 0;
    bool breaked = false;
    int i = 0;
    for (i = 0; i <= W; i++)
    {
        for (int j = 0; j < tempo.size(); j++)
        {
            if (tempo[j] <= i)
            {
                dp[i] = max(dp[i], dp[i - tempo[j]] + pont[j]);
            }
        }
        if (i - tempo[maxDenseIndex] >= 0 && dp[i] - dp[i - tempo[maxDenseIndex]] == pont[maxDenseIndex])
        {
            counter += 1;
            if (counter >= tempo[maxDenseIndex])
            {
                breaked = true;
                break;
            }
        }
        else
        {
            counter = 0;
        }
    }

    if (!breaked)
    {
        return dp[W];
    }
    else
    {
        int start = i - tempo[maxDenseIndex] + 1;
        int times = (floor)((W - start) / tempo[maxDenseIndex]);
        int index = (W - start) % tempo[maxDenseIndex] + start;
        return (times * pont[maxDenseIndex] + dp[index]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int cont = 0;
    while (cin >> n >> t && n && t)
    {
        tempo = vector<int>(n);
        pont = vector<int>(n);
        dp = vector<vector<int>>(n + 1, vector<int>(t + 1, -1));
        for (int i = 0; i < n; i++)
        {
            cin >> tempo[i] >> pont[i];
        }
        cout << "Instancia " << ++cont << endl;
        cout << unboundedKnapsack(t) << endl;
        cout << endl;
    }
}