#include <bits/stdc++.h>

using namespace std;

int survivor(int n, int k)
{
    int i, Tnk = 0;

    for (i = 1; i < n; ++i)
        Tnk = (Tnk + k) % i;

    return Tnk;
}

int main()
{
    int n;
    while (cin >> n && n)
    {
        int aux = 1;
        while (survivor(n, aux) + 2 != 13)
        {
            aux++;
        }
        cout << aux << endl;
    }
}