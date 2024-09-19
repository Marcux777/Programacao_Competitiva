#include <bits/stdc++.h>

using namespace std;

#define int long long int

signed main(){
    int n, w;
    cin >> n >> w;
    vector<int> val(n), weights(n);
    for(int i = 0; i < n; i++){
        cin >> weights[i] >> val[i];
    }
    vector<int>dp(1e5+11, INT_MAX);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 1e5+10; j >= val[i]; j--){
            dp[j] = min(dp[j], dp[j - val[i]] + weights[i]);
        }
    }

    for(int i = 1e5+10; i >= 0; i--){
        if(dp[i] <= w) {cout << i << endl; return 0;}
    }
}