#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define endl '\n'
#define INF LLONG_MIN

int N;

signed main(){
    cin >> N;
    vector<int>X(N), Y(N);
    vector<vector<int> >DP(N+1, vector<int>(2, INF));
    for(int i = 0; i < N; i++){
        cin >> X[i] >> Y[i];
    }
    DP[0][0] = 0;
    for(int i = 0; i < N; i++){
        if(X[i]) DP[i+1][1] = max(DP[i][1], DP[i][0]+Y[i]);
        else DP[i+1][0] = max(DP[i][0], max(DP[i][0], DP[i][1])+Y[i]);

        DP[i+1][0] = max(DP[i+1][0], DP[i][0]);
        DP[i+1][1] = max(DP[i+1][1], DP[i][1]);
    }
    cout << max(DP[N][0], DP[N][1]) << endl;
}