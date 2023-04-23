#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main()
{
    long double n;
    long long int ex, cont = 1;
    cin >> n;
    cout << setprecision(0) << fixed;
    while (n >= 0)
    {
        if (n >= 1)
        {
            ex = 1;
            while (n != 0)
            {
                ex = ex * 2;
                n--;
            }
        }
        else
        {
            ex = 1;
        }
        ex += 1;
        cout << "Teste " << cont << endl;
        cout << pow(ex, 2) << endl;
        cout << endl;
        cont++;
        ex = 0;
        cin >> n;
    }
}