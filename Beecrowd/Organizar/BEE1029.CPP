#include <bits/stdc++.h>
using namespace std;

int cont;

int fib(int n)
{
    cont++;
    if (n < 2)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n, x;
    cin >> n;
    while (n--)
    {
        cin >> x;
        cont = 0;
        int aux = fib(x);
        cout << "fib(" << x << ") = " << cont - 1 << " calls = " << aux << endl;
    }
}