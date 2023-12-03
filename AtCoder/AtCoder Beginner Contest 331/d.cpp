#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define endl '\n'
#define INF 1e9 + 7

int N, q;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> q;
    vector<string> grid(N);
    vector<vector<int>>v(N+1, vector<int>(N+1, 0));
    for (int i = 0; i < N; i++){
        cin >> grid[i];
        for (int j = 0; j < N; j++)
        {
            v[i+1][j+1] = v[i][j+1] + v[i+1][j] - v[i][j] + (grid[i][j] == 'B');
        }
    }
    
    while (q--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        int total = ((c/N+1)*(d/N+1)*v[N][N]) + ((c%N+1)*(d/N+1)*v[c%N+1][N]) + ((c/N+1)*(d%N+1)*v[N][d%N+1]) + ((c%N+1)*(d%N+1)*v[c%N+1][d%N+1]);
        int subtract = ((a/N+1)*(b/N+1)*v[N][N]) + ((a%N+1)*(b/N+1)*v[a%N+1][N]) + ((a/N+1)*(b%N+1)*v[N][b%N+1]) + ((a%N+1)*(b%N+1)*v[a%N+1][b%N+1]);
        cout << total-subtract << endl;
    }
}