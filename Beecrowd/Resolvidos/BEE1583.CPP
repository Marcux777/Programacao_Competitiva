#include <iostream>
using namespace std;

char x[50][50];

void mapinha(int lim1, int lim2, int i, int j)
{
    if (i > 0 && x[i - 1][j] == 'A')
    {
        x[i - 1][j] = 'T';
        mapinha(lim1, lim2, i - 1, j);
    }
    if (i < lim1 - 1 && x[i + 1][j] == 'A')
    {
        x[i + 1][j] = 'T';
        mapinha(lim1, lim2, i + 1, j);
    }
    if (j > 0 && x[i][j - 1] == 'A')
    {
        x[i][j - 1] = 'T';
        mapinha(lim1, lim2, i, j - 1);
    }
    if (j < lim2 - 1 && x[i][j + 1] == 'A')
    {
        x[i][j + 1] = 'T';
        mapinha(lim1, lim2, i, j + 1);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    while (n != 0 && m != 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> x[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (x[i][j] == 'T')
                {
                    mapinha(n, m, i, j);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << x[i][j];
            }
            cout << endl;
        }
        cout << endl;
        cin >> n >> m;
    }
}
