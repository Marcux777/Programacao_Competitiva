#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long int x, y, aux;
    while (cin >> x >> y)
    {
        aux = (x | y) & ~(x & y);
        cout << aux << endl;
    }
}
