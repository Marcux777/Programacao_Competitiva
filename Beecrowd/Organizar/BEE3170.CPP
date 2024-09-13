#include <bits/stdc++.h>
using namespace std;
int main()
{
    int b, g;
    cin >> b >> g;
    int met = g / 2;
    if (met > b)
    {
        cout << "Faltam " << met - b << " bolinha(s)" << endl;
    }
    else
    {
        cout << "Amelia tem todas bolinhas!" << endl;
    }
}