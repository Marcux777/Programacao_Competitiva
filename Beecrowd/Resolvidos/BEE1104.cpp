#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, y, aux, cont = 0;
    set<int> mp1, mp2;
    cin >> x >> y;
    while (x && y)
    {
        for (int i = 1; i <= x; i++)
        {
            cin >> aux;
            mp1.insert(aux);
        }
        for (int i = 1; i <= y; i++)
        {
            cin >> aux;
            mp2.insert(aux);
        }
        if (mp1.size() >= mp2.size())
        {
            for (auto it = mp2.begin(); it != mp2.end(); it++)
            {
                int a = *it;
                if (!mp1.count(a))
                {
                    cont++;
                }
            }
        }
        else
        {
            for (auto it = mp1.begin(); it != mp1.end(); it++)
            {
                int a = *it;
                if (!mp2.count(a))
                {
                    cont++;
                }
            }
        }

        cout << cont << endl;
        mp1.clear();
        mp2.clear();
        cont = 0;
        cin >> x >> y;
    }
}