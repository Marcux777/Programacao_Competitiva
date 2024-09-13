#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, cont1 = 0, cont2 = 0;
    cin >> n >> m;
    int v[2][n];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (v[0][i] == 1)
        {
            cont1++;
        }
    }
    if (cont1 == m)
    {
        cout << "Tudo certo.\n";
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (v[1][i] == 1)
            {
                cont2++;
            }
        }
        if (cont2 == m)
        {
            cout << "Pegou de Samuel.\n";
        }
        else
        {
            cout << "Pegou de um estranho.\n";
        }
    }
}