#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("saida.txt", "w", stdout);
    int n;
    int v[4][4];

    cin >> n;

    while (n--)
    {
        
        int none = 0;
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                cin >> v[i][j];
                if (v[i][j] == 2048)
                    none = 1;
            }
        }

        if (none)
        {
            cout << "NONE\n";
            continue;
        }

        int down = 0;
        for (int i = 0; i < 4 && !down; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if ((v[j][i] != 0 && v[j + 1][i] == 0) || (v[j][i] == v[j + 1][i] && v[j][i]))
                    down = 1;
            }
        }

        int left = 0;
        for (int i = 0; i < 4 && !left; ++i)
        {
            for (int j = 1; j < 4; ++j)
            {
                if ((v[i][j - 1] == 0 && v[i][j] != 0) || (v[i][j - 1] == v[i][j] && v[i][j]))
                    left = 1;
            }
        }

        int right = 0;
        for (int i = 0; i < 4 && !right; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if ((v[i][j + 1] == 0 && v[i][j] != 0) || (v[i][j + 1] == v[i][j] && v[i][j]))
                    right = 1;
            }
        }

        int up = 0;
        for (int i = 0; i < 4 && !up; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if ((v[j + 1][i] != 0 && v[j][i] == 0) || (v[j][i] == v[j + 1][i] && v[j][i]))
                    up = 1;
            }
        }

        if (!down && !left && !right && !up)
        {
            cout << "NONE";
        }

        int escrevi = 0;

        if (down)
        {
            cout << "DOWN";
            escrevi = 1;
        }

        if (left)
        {
            if (escrevi)
                cout << ' ';
            escrevi = 1;
            cout << "LEFT";
        }

        if (right)
        {
            if (escrevi)
                cout << ' ';
            escrevi = 1;
            cout << "RIGHT";
        }

        if (up)
        {
            if (escrevi)
                cout << ' ';
            escrevi = 1;
            cout << "UP";
        }

        cout << '\n';
    }
}
