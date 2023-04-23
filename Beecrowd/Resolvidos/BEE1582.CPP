#include <iostream>
#include <math.h>
using namespace std;
bool E_Primo(int x, int y, int z)
{
    int div;
    bool mdc = true;
    for (div = 2; div <= x; div++)
    {
        if ((x % div == 0) && (y % div == 0) && (z % div == 0))
        {
            mdc = false;
        }
    }
    return mdc;
}
int main()
{
    int aux;
    int a, b, c;
    while (cin >> a >> b >> c)
    {
        if (a > b)
        { // a é maior que b
            if (a > c)
            { // a é maior que c
                if (b < c)
                { // b é menor que c
                    aux = b;
                    b = c;
                    c = aux;
                }
            }
            else
            { //'c' é o maior de todos e 'a' é o segundo maior
                aux = a;
                a = c;
                c = aux;
                aux = b;
                b = c;
                c = aux;
            }
        }
        else if (b > a)
        { // b é maior que 'a'
            aux = a;
            a = b;
            b = aux;
            if (a < c)
            { // c é o maior
                aux = a;
                a = c;
                c = aux;
                aux = b;
                b = c;
                c = aux;
            }
            if (b < c)
            { // b é menor que c
                aux = b;
                b = c;
                c = aux;
            }
        }
        else
        { // c > a
            aux = a;
            a = c;
            c = aux; // a é maior que c
            if (b < c)
            { // b é menor de todos
                aux = b;
                b = c;
                c = aux;
            }
        }
        if (a * a == (b * b + c * c))
        {
            if (E_Primo(a, b, c))
            {
                cout << "tripla pitagorica primitiva" << endl;
            }
            else
            {
                cout << "tripla pitagorica" << endl;
            }
        }
        else
        {
            cout << "tripla" << endl;
        }
    }
}