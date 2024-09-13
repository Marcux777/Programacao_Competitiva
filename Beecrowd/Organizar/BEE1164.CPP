#include <iostream>
using namespace std;
int main()
{
    int n, x, soma;
    cin >> n;
    soma = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        for (int j = 1; j < x; j++)
        {
            if (x % j == 0)
            {
                soma += j;
            }
        }
        if (soma == x)
        {
            cout << x << " eh perfeito" << endl;
        }
        else
        {
            cout << x << " nao eh perfeito" << endl;
        }
        soma = 0;
    }
}