#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double M[12][12];
    char O;
    float soma;
    soma = 0;
    cin >> O;
    cout << setprecision(1) << fixed;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            cin >> M[i][j];
        }
    }
    for (int j = 0; j < 12; j++)
    {
        for (int i = 0; i < 12; i++)
        {
            if (i > j)
            {
                soma += M[i][j];
            }
        }
    }
    if (O == 'S')
    {
        cout << soma << endl;
    }
    else if (O == 'M')
    {
        cout << soma / 66.0 << endl;
    }
}