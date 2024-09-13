#include <iostream>
using namespace std;
int main()
{
    int tp, a, b, c, d, e, cont = 0;
    cin >> tp;
    cin >> a;
    if (a == tp)
    {
        cont++;
    }
    cin >> b;
    if (b == tp)
    {
        cont++;
    }
    cin >> c;
    if (c == tp)
    {
        cont++;
    }
    cin >> d;
    if (d == tp)
    {
        cont++;
    }
    cin >> e;
    if (e == tp)
    {
        cont++;
    }
    cout << cont << endl;
}