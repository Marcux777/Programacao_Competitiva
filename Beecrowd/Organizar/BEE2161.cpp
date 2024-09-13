#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    long double raiz = 0.0, aux = 3.0;
    int n;
    cout << setprecision(10) << fixed;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        raiz += 6.0;
        raiz = 1.0 / raiz;
    }
    cout << raiz + aux << endl;
}