#include <iostream>
using namespace std;
int lesma_rapida(int *x, int pos)
{
    int maior = -1000;
    for (int i = 0; i < pos; i++)
    {
        if (x[i] > maior)
        {
            maior = x[i];
        }
    }
    if (maior < 10)
    {
        return 1;
    }
    else if (maior >= 10 && maior < 20)
    {
        return 2;
    }
    else
    {
        return 3;
    }
}

int main()
{
    int l, m;
    int v[500];
    while (cin >> l)
    {
        for (int i = 0; i < l; i++)
        {
            cin >> v[i];
        }
        cout << lesma_rapida(v, l) << endl;
    }
}