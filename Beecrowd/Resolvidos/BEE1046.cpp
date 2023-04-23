#include <iostream>

using namespace std;

int main()
{
    int a, b, h, aux;
    cin >> a >> b;
    if (a < b)
    {
        h = a - b;
        cout << "O JOGO DUROU " << h * -1 << " HORA(S)" << endl;
    }
    else if (a > b)
    {
        h = (24 - a) + b;
        cout << "O JOGO DUROU " << h << " HORA(S)" << endl;
    }
    if (a == b)
    {
        cout << "O JOGO DUROU 24 HORA(S)" << endl;
    }
    return 0;
}