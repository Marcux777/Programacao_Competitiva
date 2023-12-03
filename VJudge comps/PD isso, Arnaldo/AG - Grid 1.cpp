#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define endl '\n'
#define INF LLONG_MAX
#define mod 1000000007

vector<vector<int>> DP;
vector<vector<char>> graph;
int N, M;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    graph.assign(N, vector<char>(M));
    DP.assign(N, vector<int>(M, 0));
    for (auto &i : graph)
        for (auto &j : i)
            cin >> j;

    DP[0][0] = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (graph[i][j] != '#')
            {
                if (i - 1 >= 0)
                    DP[i][j] += DP[i - 1][j];

                if (j - 1 >= 0)
                    DP[i][j] += DP[i][j - 1];
                DP[i][j] %= mod;
            }
        }
    }
    cout << DP[N - 1][M - 1] << endl;
}