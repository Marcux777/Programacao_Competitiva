#include <bits/stdc++.h>

using namespace std;

int max_sum_of_grids(int N, int M, const vector<vector<int>>& grid) {
    vector<vector<int>> sum(N+1, vector<int>(N+1, 0));

    // Pré-calcular as somas de todas as subgrades possíveis
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            sum[i][j] = grid[i-1][j-1] - sum[i-1][j-1] + sum[i-1][j] + sum[i][j-1];

    auto get_sum = & {
        return sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];
    };

    int max_sum = 0;

    // Iterar sobre todas as posições possíveis para as três grades M×M
    for (int i1 = M; i1 <= N; ++i1)
        for (int j1 = M; j1 <= N; ++j1)
            for (int i2 = M; i2 <= N; ++i2)
                for (int j2 = M; j2 <= N; ++j2)
                    for (int i3 = M; i3 <= N; ++i3)
                        for (int j3 = M; j3 <= N; ++j3)
                            if ((i1-M+1 > i2 || i1 < i2-M+1 || j1-M+1 > j2 || j1 < j2-M+1) &&
                                (i1-M+1 > i3 || i1 < i3-M+1 || j1-M+1 > j3 || j1 < j3-M+1) &&
                                (i2-M+1 > i3 || i2 < i3-M+1 || j2-M+1 > j3 || j2 < j3-M+1))
                                max_sum = max(max_sum, get_sum(i1-M+1, j1-M+1, i1, j1) +
                                                      get_sum(i2-M+1, j2-M+1, i2, j2) +
                                                      get_sum(i3-M+1, j3-M+1, i3, j3));

    return max_sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>>grid(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    cout << max_sum_of_grids(n, m, grid) << endl;
}
