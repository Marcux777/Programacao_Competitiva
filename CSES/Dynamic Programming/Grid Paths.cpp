#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define endl '\n'
#define INF INT_MAX
#define mod 1000000007

vector<vector<int>> DP;
vector<string> grid;
int N;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    grid.resize(N);
    DP.assign(N, vector<int>(N, 0));
    DP[0][0] = 1;
    for (auto &i : grid)
        cin >> i;

    if(grid[0][0] == '*'){cout << 0 << endl; return 0;}
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] != '*')
            {
                if (i - 1 >= 0)
                    DP[i][j] += DP[i - 1][j];
                if (j - 1 >= 0)
                    DP[i][j] += DP[i][j - 1];
                DP[i][j] %= mod;
            }
        }
    }
    cout << DP[N - 1][N - 1] << endl;
}