#include <bits/stdc++.h>
using namespace std;

#define mod 998244353
#define endl '\n'
#define int long long int
#define INF 1e18 + 100
int N, M;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    vector<int>A(N);
    vector<int>B(M);
    vector<vector<int> >DP(N+1, vector<int>(M+1, INF));
    for(auto &i : A) cin >> i;
    for(auto &i : B) cin >> i;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= M; j++){
            if(i == 0 || j == 0) DP[i][j] = i+j;
            else DP[i][j] = min({DP[i-1][j]+1, DP[i][j-1]+1, DP[i-1][j-1] + (A[i] != B[j])});
        }
    }
    cout << DP[N][M] << endl;
    
}
