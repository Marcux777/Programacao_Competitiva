#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
const int inf = 1e15;
#define Ninf LLONG_MIN
#define mod 1000000007

vector<vector<string>> v;
unordered_map<string, int> memo;

int f(const string &s, const string &t, int index)
{
    if (index == t.size())
        return 0;
    if (memo.count(t.substr(index)))
        return memo[t.substr(index)];

    int minCost = inf;
    for (int i = 0; i < v.size(); ++i)
    {
        for (const string &str : v[i])
        {
            if (t.substr(index, str.size()) == str)
            {
                int cost = f(s, t, index + str.size());
                if (cost != inf)
                {
                    minCost = min(minCost, cost + 1);
                }
            }
        }
    }

    memo[t.substr(index)] = minCost; // Save the result in the memo table
    return minCost;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s, st;
    cin >> s;
    int n, m;
    cin >> n;
    vector<vector<string>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        v[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    int a = f(s, s, 0);

    cout << (a == inf ? -1 : a) << endl;
}