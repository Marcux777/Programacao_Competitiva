#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrix_mult(const vector<vector<int>>& a, const vector<vector<int>>& b, int n)
{
    vector<vector<int>> c(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            for (int j = 0; j < n; j++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return c;
}

vector<vector<int>> matrix_pow(const vector<vector<int>>& a, int b, int n)
{
    if (b == 0)
    {
        vector<vector<int>> identity(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            identity[i][i] = 1;
        }
        return identity;
    }

    if (b % 2 == 1)
    {
        return matrix_mult(a, matrix_pow(a, b - 1, n), n);
    }

    vector<vector<int>> half = matrix_pow(a, b / 2, n);
    return matrix_mult(half, half, n);
}

string decode(int n, int m, const vector<int>& p, const string& s)
{
    // Calcular a matriz de permutação
    vector<vector<int>> perm(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        perm[i][p[i] - 1] = 1;
    }

    // Calcular a matriz de permutação elevada à m
    vector<vector<int>> perm_m = matrix_pow(perm, m, n);

    // Decodificar a string
    string decoded(n, ' ');
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (perm_m[j][i] == 1)
            {
                decoded[i] = s[j];
            }
        }
    }

    return decoded;
}

int main()
{
    //freopen("saida.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long int N, M;
    while (cin >> N >> M && N && M)
    {

        vector<int> permutacao(N);
        for (int i = 0; i < N; i++)
        {
            cin >> permutacao[i];
        }
        cin.ignore();
        string texto_cifrado;
        getline(cin, texto_cifrado);
        cout << decode(N, M, permutacao, texto_cifrado) << endl;
    }

    return 0;
}
