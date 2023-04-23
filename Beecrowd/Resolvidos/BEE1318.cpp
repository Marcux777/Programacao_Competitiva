#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m, n;
    while (cin >> m >> n && m && n)
    {
        int v[n], cont = 0;
        bool vis[m + 1] = {false};
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (v[j] == v[i] && !vis[v[i]])
                {
                    cont++;
                    vis[v[i]] = true;
                }
            }
        }
        cout << cont << endl;
    }
}