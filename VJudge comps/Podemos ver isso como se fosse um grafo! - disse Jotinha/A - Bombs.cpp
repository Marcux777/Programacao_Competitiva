#include <bits/stdc++.h>

using namespace std;

//Eu sou uma mula mesmo

vector<vector<bool>> vis;

void visit(int x, int y, int r, int c, int poder)
{

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            if (abs(x - i) + abs(y - j) <= poder)
            {
                vis[i][j] = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("saida.txt", "w", stdout);
    int r, c;
    cin >> r >> c;
    vector<string> grid(r);
    for (int i = 0; i < r; i++)
    {
        cin >> grid[i];
    }
    vis.assign(r, vector<bool>(c, false));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (isdigit(grid[i][j]))
            {
                visit(i, j, r, c, grid[i][j] - '0');
            }
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (vis[i][j])
                cout << ".";
            else
                cout << grid[i][j];
        }
        cout << endl;
    }
}