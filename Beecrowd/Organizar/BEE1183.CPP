#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double M[12][12];
    char m;
    float soma;
    cout << setprecision(1) << fixed;
    cin >> m;
    soma = 0;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            cin >> M[i][j];
        }
    }
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (j > i)
            {
                soma += M[i][j];
            }
        }
    }
    if (m == 'S')
    {
        cout << soma << endl;
    }
    else if (m == 'M')
    {
        cout << soma / 66.0 << endl;
    }
}