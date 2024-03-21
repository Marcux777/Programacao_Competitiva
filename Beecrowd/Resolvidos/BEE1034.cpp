#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define inf INT_MAX
#define Ninf LLONG_MIN
#define mod 1000000007

int n, m;

vector<int> v;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        v = vector<int>(n);
        for (auto &i : v)
            cin >> i;
        sort(v.begin(), v.end());
        vector<int> dp(m+1, inf);
        dp[0] = 0;
        for(auto i : v){
            for(int j = i; j <= m; j++){
                dp[j] = min(dp[j], dp[j-i] + 1);
            }
        }
        cout << dp[m] << endl;
    }
}