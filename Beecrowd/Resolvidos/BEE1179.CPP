#include <iostream>
using namespace std;
int main()
{
    int par[5], impar[5];
    int x = 0, p = 0, i = 0, a = 0, b = 0;
    for (int j = 0; j < 15; j++)
    {
        cin >> x;
        if (x % 2 == 0)
        {
            par[p] = x;
            p++;
        }
        else
        {
            impar[i] = x;
            i++;
        }
        if (p == 5)
        {
            p = 0;
            while (a != 5)
            {
                cout << "par[" << a << "] = " << par[a] << endl;
                a++;
            }
        }
        if (i == 5)
        {
            i = 0;
            while (b != 5)
            {
                cout << "impar[" << b << "] = " << impar[b] << endl;
                b++;
            }
        }
        if (j == 14)
        {
            b = 0;
            a = 0;
            while (b < i)
            {
                cout << "impar[" << b << "] = " << impar[b] << endl;
                b++;
            }
            while (a < p)
            {
                cout << "par[" << a << "] = " << par[a] << endl;
                a++;
            }
        }
    }
}