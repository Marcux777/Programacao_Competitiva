#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define endl '\n'
#define INF LLONG_MAX
#define mod 1000000007

vector<int> DP;
int N;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    DP.assign(N+1, 0);
    DP[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= 6; j++){
            if(i - j >= 0){
                DP[i] += DP[i-j];
                DP[i] %= mod;
            }
        }
    }
    cout << DP[N] << endl;
}