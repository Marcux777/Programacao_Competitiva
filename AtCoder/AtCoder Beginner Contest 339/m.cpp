#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define endl '\n'
#define INF 1e9 + 7

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, d; cin >> n >> d;
    vector<int> v(n);
    for(auto &i : v) cin >> i;

    vector<int> dp(n, 1);
    vector<pair<int, int>> id(n);
    for(int i = 0; i < n; i++){
        id[i] = {v[i], i};
    }
    sort(id.begin(), id.end());
    multiset<int> s;
    for(int i = 0; i < n; i++){
        while(!s.empty() && id[i].first - *s.begin() > d) {
            s.erase(s.begin());
        }
        if(!s.empty()) {
            dp[id[i].second] = max(dp[id[i].second], *s.rbegin() + 1);
        }
        s.insert(dp[id[i].second]);
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
}
