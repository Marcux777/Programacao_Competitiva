#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double M[12][12];
    char m;
    float soma;
    int cont;
    cout << setprecision(1) << fixed;
    cin >> m;
    soma = 0;
    cont = 12;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            cin >> M[i][j];
        }
    }
    for (int i = 0; i <= 11; i++)
    {
        for (int j = 0; j <= cont; j++)
        {
            if (j < 11 - i)
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