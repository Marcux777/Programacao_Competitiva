#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m, n;
    while (cin >> m >> n)
    {
        int l = 0, saca = 0;
        int mat[m][n];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat[i][j];
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                l += mat[i][j];
            }
        }
        saca = l / 60;
        cout << saca << " saca(s) e " << l % 60 << " litro(s)" << endl;
    }
}