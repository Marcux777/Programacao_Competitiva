#include <iostream>
#include <vector>

using namespace std;

int maxGasoline(const vector<vector<char>> &v, int N, int M, int L)
{
    vector<vector<int>> SomaC(N, vector<int>(M, 0));
    vector<vector<int>> SomaM(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            SomaC[i][j] = (v[i][j] == 'C') + (j > 0 ? SomaC[i][j - 1] : 0);
            SomaM[i][j] = (v[i][j] == 'M') + (j > 0 ? SomaM[i][j - 1] : 0);
        }

        if (i > 0)
        {
            for (int j = 0; j < M; j++)
            {
                SomaC[i][j] += SomaC[i - 1][j];
                SomaM[i][j] += SomaM[i - 1][j];
            }
        }
    }

    int maxGas = -1;

    for (int i = 0; i <= N - L; i++)
    {
        for (int j = 0; j <= M - L; j++)
        {
            int Carros = SomaC[i + L - 1][j + L - 1];
            int Motos = SomaM[i + L - 1][j + L - 1];

            if (i > 0)
            {
                Carros -= SomaC[i - 1][j + L - 1];
                Motos -= SomaM[i - 1][j + L - 1];
            }

            if (j > 0)
            {
                Carros -= SomaC[i + L - 1][j - 1];
                Motos -= SomaM[i + L - 1][j - 1];
            }

            if (i > 0 && j > 0)
            {
                Carros += SomaC[i - 1][j - 1];
                Motos += SomaM[i - 1][j - 1];
            }

            if (Carros > 0 && Motos > 0)
            {
                maxGas = max(maxGas, Carros * 25 + Motos * 12);
            }
        }
    }

    return maxGas;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<char>> v(N, vector<char>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> v[i][j];
        }
    }

    int L;
    cin >> L;

    int result = maxGasoline(v, N, M, L);
    cout << result << endl;

    return 0;
}
