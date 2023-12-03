#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, p, q;
    cin >> t;
    while (t--)
    {
        cin >> p >> q;
        if (p % 2 == 0 || q % 2 == 0)
            cout << "Ashish\n";
        else
            cout << "Jeel\n";
    }
}