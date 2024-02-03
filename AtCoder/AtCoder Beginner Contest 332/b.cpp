#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define endl '\n'

signed main()
{
    int copoC, canecaC, k;
    cin >> k >> copoC >> canecaC;
    int copo = 0, caneca = 0;
    while (k--)
    {
        if (copo == copoC)
        {
            copo = 0;
        }
        else if (caneca == 0)
            caneca = canecaC;
        else
        {
            int x = caneca;
            caneca -= (copoC - copo);
            if(caneca < 0) caneca = 0;
            copo += x - caneca;
        }
    }
    cout << copo << " " << caneca << endl;
}