#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define inf INT_MAX
#define Ninf LLONG_MIN
#define mod 1000000007

int n, p;
vector<vector<int>> dp;

vector<int> pizza;
vector<int> tempo;

int f(int id, int weight)
{
    if (id >= n)
        return 0;
    if (weight >= p)
        return 0;
    if (dp[id][weight] != -1)
        return dp[id][weight];
    int a = f(id + 1, weight);
    //cout << a << endl;
    if (pizza[id] + weight <= p)
    {
        int resp = f(id + 1, weight + pizza[id]) + tempo[id];
        a = max(a, resp);
    }
    return dp[id][weight] = a;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (cin >> n && n)
    {
        cin >> p;
        dp = vector<vector<int>>(n + 1, vector<int>(p + 1, -1));
        pizza = vector<int>(n);
        tempo = vector<int>(n);

        for (int i = 0; i < n; i++)
        {
            cin >>  tempo[i] >> pizza[i];
        }
        cout << f(0, 0) << " min." << endl;
    }
}