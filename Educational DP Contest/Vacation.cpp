#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define inf LLONG_MAX
#define Ninf LLONG_MIN

vector<vector<int>> DP;
vector<vector<int>> mat;

int f(int n, int d)
{
    if (n == mat.size())
        return 0;
    if (DP[n][d] != -1)
        return DP[n][d];

    int A, B, C;
    A = B = C = 0;
    if (d == 0)
    {
        A = f(n + 1, 1) + mat[n][0];
        B = f(n + 1, 2) + mat[n][1];
        C = f(n + 1, 3) + mat[n][2];
    }
    if (d == 1)
    {
        B = f(n + 1, 2) + mat[n][1];
        C = f(n + 1, 3) + mat[n][2];
    }
    if (d == 2)
    {
        A = f(n + 1, 1) + mat[n][0];
        C = f(n + 1, 3) + mat[n][2];
    }
    if (d == 3)
    {
        A = f(n + 1, 1) + mat[n][0];
        B = f(n + 1, 2) + mat[n][1];
    }
    return DP[n][d] = max(max(A, B), C);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    DP = vector<vector<int>>(n, vector<int>(4, -1));
    mat = vector<vector<int>>(n, vector<int>(3));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> mat[i][j];

    cout << f(0, 0) << endl;
}