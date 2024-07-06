#include <bits/stdc++.h>

using namespace std;

vector<int> dp;
vector<int> val, wt;
int n, W;


int main(){
    cin >> n >> W;
    val.resize(n), wt.resize(n);
    dp = vector<int> (W+1, 0);
    for(int i = 0; i < n; i++){
        cin >> val[i] >> wt[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = wt[i]; j <= W; j++){
            dp[j] = max(dp[j], dp[j - wt[i]] + val[i]);
        }
    }

    cout << dp[W] << endl;
}