#include <iostream>
#include <string>
using namespace std;
int main()
{
    string date, dia;
    long int n, p, v, c, d, aux;
    while (cin >> p >> n)
    {
        aux = 0;
        c = 0;
        d = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> date;
            for (int j = 0; j < p; j++)
            {
                cin >> v;
                if (v == 1)
                {
                    c++;
                }
            }
            if (c == p)
            {
                if (aux == 0)
                {
                    dia = date;
                    aux = 1;
                }
            }
            else
            {
                d++;
            }
            c = 0;
        }
        if (d == n)
        {
            cout << "Pizza antes de FdI" << endl;
        }
        else
        {
            cout << dia << endl;
        }
    }
}