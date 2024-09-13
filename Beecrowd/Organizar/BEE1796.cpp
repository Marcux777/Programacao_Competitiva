#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, cont1 = 0, cont2 = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a)
        {
            cont1++;
        }
        else
        {
            cont2++;
        }
    }
    if (cont1 >= cont2)
    {
        cout << "N\n";
    }
    else
    {
        cout << "Y\n";
    }
}