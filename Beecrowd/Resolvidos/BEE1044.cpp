#include <iostream>

using namespace std;

int main()
{
    int a, b, aux;
    cin >> a >> b;
    if (b > a)
    {
        aux = a;
        a = b;
        b = aux;
    }
    if (a % b == 0)
    {
        cout << "Sao Multiplos" << endl;
    }
    else
    {
        cout << "Nao sao Multiplos" << endl;
    }
}