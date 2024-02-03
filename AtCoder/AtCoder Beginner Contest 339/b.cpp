#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define endl '\n'
#define INF 1e9 + 7

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int w, h, n;
    cin >> h >> w >> n;
    vector<vector<bool>> grid(h, vector<bool>(w, false));

    int atualL = 0, atualC = 0, direct = 0;
    for (int i = 0; i < n; ++i)
    {
        if (!grid[atualL][atualC])
        {
            grid[atualL][atualC] = true;
            direct = (direct + 1) % 4;
        }
        else
        {
            grid[atualL][atualC] = false;
            direct = (direct + 3) % 4;
        }

        if (direct == 0)
        {
            // cima
            atualL = (atualL - 1 + h) % h;
        }
        else if (direct == 1)
        {
            // direita
            atualC = (atualC + 1) % w;
        }
        else if (direct == 2)
        {
            // baixo
            atualL = (atualL + 1) % h;
        }
        else
        {
            // esquerda
            atualC = (atualC - 1 + w) % w;
        }
    }

    for (auto i : grid)
    {
        for (auto j : i)
            cout << (j ? '#' : '.');
        cout << endl;
    }
}