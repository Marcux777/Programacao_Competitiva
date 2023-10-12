#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;

char grid[101][101];
ll val[101][101];
ll rows, cols;
vl dx = {0, 1, 0, -1, 1, -1, 1, -1};
vl dy = {1, 0, -1, 0, 1, 1, -1, -1};
ll whiteSpaces, blackSpaces, num, size, flag;

void flood_fill(int i, int j, char oldColor, char newColor, ll type)
{
    if (grid[i][j] != oldColor)
        return;
    grid[i][j] = newColor;

    if (type == 2)
    {
        size++;
        if (num == -1 && val[i][j] != -1)
            num = val[i][j];
        else if (num != -1 && val[i][j] != -1)
        {
            num = -1;
            return;
        }
    }

    for (int z = 0; z < ((type == 3) ? 8 : 4); z++)
    {
        int x = i + dx[z];
        int y = j + dy[z];
        if (x < 0 || x == rows || y < 0 || y == cols)
        {
            if (type == 3)
                flag = 1;
            continue;
        }
        if (grid[x][y] == oldColor)
            flood_fill(x, y, oldColor, newColor, type);
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;

    while (t--)
    {
        ll d, x, y, v;
        cin >> rows >> cols >> d;

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                val[i][j] = -1;

        bool verif = 1;
        for (int i = 0; i < d; i++)
        {
            cin >> x >> y >> v;
            val[x][y] = v;
        }

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
            {
                cin >> grid[i][j];
                if (val[i][j] != -1 && grid[i][j] == '#')
                    verif = 0;
            }

        ll blackCount = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == '#')
                {
                    blackCount++;
                    flood_fill(i, j, '#', 'O', 1);
                }
            }
        }

        // mais de um componente junto ao preto, deu ruim
        if (blackCount > 1)
        {
            cout << "not solved\n";
            continue;
        }

        for (int i = 0; i < rows && verif; i++)
        {
            for (int j = 0; j < cols && verif; j++)
            {
                if (grid[i][j] == '.')
                {
                    num = -1;
                    size = 0;

                    flood_fill(i, j, '.', 'P', 2);
                    if (size != num)
                        verif = 0;
                }
            }
        }

        if (!verif)
        {
            cout << "not solved\n";
            continue;
        }

        for (int i = 0; i < rows && verif; i++)
        {
            for (int j = 0; j < cols && verif; j++)
            {
                if (grid[i][j] == 'P')
                {
                    flag = 0;
                    flood_fill(i, j, 'P', '.', 3);
                    if (!flag)
                        verif = 0;
                }
            }
        }

        if (!verif)
        {
            cout << "not solved\n";
            continue;
        }

        for (int i = 0; i < rows - 1 && verif; i++)
        {
            for (int j = 0; j < cols - 1 && verif; j++)
            {
                if (!(grid[i][j] == '.' || grid[i + 1][j] == '.' || grid[i][j + 1] == '.' || grid[i + 1][j + 1] == '.'))
                    verif = 0;
            }
        }

        if (!verif)
        {
            cout << "not solved\n";
            continue;
        }

        cout << "solved\n";
    }
}
