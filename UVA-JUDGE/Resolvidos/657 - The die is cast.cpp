#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void dfs(vector<string> &v, int x, int y, int linha, int col)
{
    if (x < 0 || y < 0 || x >= linha || y >= col)
    {
        return;
    }
    v[x][y] = '*';
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < linha && ny >= 0 && ny < col && v[nx][ny] == 'X')
        {
            dfs(v, nx, ny, linha, col);
        }
    }
}

void floodfill(vector<string> &v, int x, int y, int linha, int col, int &ans)
{
    if (x < 0 || y < 0 || x >= linha || y >= col)
    {
        return;
    }
    if (v[x][y] == 'X')
    {
        ans++;
        dfs(v, x, y, linha, col);
    }
    v[x][y] = '.';

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < linha && ny >= 0 && ny < col && v[nx][ny] != '.')
        {
            floodfill(v, nx, ny, linha, col, ans);
        }
    }
}

int main()
{
    //freopen("saida.txt", "w", stdout);
    int h, w, t = 0;
    while (cin >> w >> h && (w || h))
    {
        vector<string> v(h);
        int resp[100] = {0};
        for (int i = 0; i < h; i++)
        {
            cin >> v[i];
        }
        int pos = 0;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (v[i][j] == '*')
                {
                    floodfill(v, i, j, h, w, resp[pos]);
                    pos++;
                }
            }
        }
        sort(resp, resp + pos);
        cout << "Throw " << ++t << endl;
        for (int i = 0; i < pos; i++)
        {
            cout << resp[i] << (i < pos - 1 ? " " : "\n");
        }
        cout << endl;
    }
}