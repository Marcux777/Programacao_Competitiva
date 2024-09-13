#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, maior, segmaior;
    while (cin >> n && n)
    {
        maior = segmaior = -99999;
        int v[n];
        int pos = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] > maior)
            {
                maior = v[i];
            }
        }
        // cout << maior << endl;
        for (int i = 0; i < n; i++)
        {
            if (v[i] > segmaior && v[i] != maior)
            {
                pos = i + 1;
                segmaior = v[i];
            }
        }
        // cout << segmaior << endl;
        cout << pos << endl;
    }
}