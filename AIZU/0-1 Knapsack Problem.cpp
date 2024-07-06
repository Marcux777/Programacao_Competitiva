#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp;
vector<int> val, wt;

int n, W;

int f(int id, int w){
    if(id > n) return 0;
    if(w > W) return 0;
    if(dp[id][w] != -1) return dp[id][w];

    int a = f(id+1, w);
    if(wt[id] + w <= W){
        int r = f(id + 1, w + wt[id]) + val[id];
        a = max(a, r);
    }
    return dp[id][w] = a;
}

int main(){
    
    cin >> n >> W;
    val.resize(n), wt.resize(n);
    for(int i = 0; i < n; i++){
        cin >> val[i] >> wt[i];
    }

    dp = vector<vector<int>>(n+1, vector<int>(W+1, -1));

    cout << f(0, 0) << endl;

}