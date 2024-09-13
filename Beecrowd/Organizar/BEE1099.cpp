#include <iostream>
using namespace std;

int somaimpar(int a, int b)
{
    int aux, soma = 0;
    if (a > b)
    {
        aux = a;
        a = b;
        b = aux;
    }
    for (int i = a + 1; i < b; i++)
    {
        if (i % 2 == 1)
        {
            soma += i;
        }
    }
    return soma;
}

int main()
{
    int n, x, y;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        cout << somaimpar(x, y) << endl;
    }
}