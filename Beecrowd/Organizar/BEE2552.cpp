#include <iostream>
using namespace std;
int main()
{
    int quejo[105][105];
    int n, m, aux;
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> quejo[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (quejo[i][j] == 1)
                {
                    cout << 9;
                }
                else
                {
                    aux = 0;
                    if (i > 0)
                    {
                        aux += quejo[i - 1][j];
                    }
                    if (j > 0)
                    {
                        aux += quejo[i][j - 1];
                    }
                    if (i != n - 1)
                    {
                        aux += quejo[i + 1][j];
                    }
                    if (j != m - 1)
                    {
                        aux += quejo[i][j + 1];
                    }
                    cout << aux;
                }
                if (j == m - 1)
                {
                    cout << endl;
                }
            }
        }
    }
}