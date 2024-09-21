#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    if (m == 0) {
        cout << 1 << endl;
        return 0;
    }
    
    vector<pair<int, int>> edges;
    set<int> s;
    s.insert(0);
    
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        s.insert(x);
        s.insert(y);
        edges.emplace_back(x, y);
    }
    
    vector<int> sorted_s(s.begin(), s.end());
    unordered_map<int, int> d;
    int sz = sorted_s.size();
    
    for (int i = 0; i < sz; ++i) {
        d[sorted_s[i]] = i;
    }
    
    vector<vector<pair<int, int>>> edge(sz);
    for (int i = 0; i < sz; ++i) {
        edge[i].emplace_back((i + 1) % sz, (sorted_s[(i + 1) % sz] - sorted_s[i] + n) % n);
    }
    
    for (const auto& e : edges) {
        int x = e.first, y = e.second;
        edge[d[x]].emplace_back(d[y], 1);
    }
    
    vector<vector<int>> dp(k, vector<int>(sz, 0));
    dp[0][0] = 1;
    int ans = 0;
    
    for (int i = 0; i < k; ++i) {
        for (int v = 0; v < sz; ++v) {
            for (const auto& [to, w] : edge[v]) {
                if (i + w >= k) {
                    ans = (ans + dp[i][v]) % MOD;
                } else {
                    dp[i + w][to] = (dp[i + w][to] + dp[i][v]) % MOD;
                }
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}