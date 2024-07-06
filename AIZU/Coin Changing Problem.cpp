#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<int> v(m), dp(n+1, INT_MAX);
    for(auto &i : v) cin >> i;
    sort(v.begin(), v.end());
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            if(v[j] <= i){
                dp[i] = min(dp[i], dp[i-v[j]] + 1);
            }
        }
    }
    cout << dp[n] << endl;
}