#include <iostream>
using namespace std;
int main()
{
    int x, z, i = 0, soma;
    cin >> x;
    cin >> z;
    soma = 0;
    while (z <= x)
    {
        cin >> z;
    }
    while (soma < z)
    {
        soma += x;
        x++;
        i++;
    }
    cout << i << endl;
}