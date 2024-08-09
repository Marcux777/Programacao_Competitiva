#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), dp(x+1);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = x; j >= a[i]; j--){
            dp[j] = max(dp[j], dp[j-a[i]]+b[i]);
        }
    }
    cout << dp[x] << endl;
}