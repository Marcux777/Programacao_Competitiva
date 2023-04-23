#include <iostream>
using namespace std;
int main()
{
    int x, y, aux, soma = 0;
    cin >> x;
    cin >> y;
    if (x > y)
    {
        aux = x;
        x = y;
        y = aux;
    }
    for (int i = x; i <= y; i++)
    {
        if (i % 13 != 0)
        {
            soma += i;
        }
    }
    cout << soma << endl;
}