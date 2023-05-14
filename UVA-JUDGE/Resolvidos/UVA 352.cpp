#include <bits/stdc++.h>

using namespace std;

char mat[26][26];
bool vis[26][26];

void floodfill(int i, int j, int lim)
{
    vis[i][j] = true;
    if (i > 0 && mat[i - 1][j] == '1' && !vis[i - 1][j])
    {
        floodfill(i - 1, j, lim);
    }
    if (i < lim && mat[i + 1][j] == '1' && !vis[i + 1][j])
    {
        floodfill(i + 1, j, lim);
    }
    if (j > 0 && mat[i][j - 1] == '1' && !vis[i][j - 1])
    {
        floodfill(i, j - 1, lim);
    }
    if (j < lim && mat[i][j + 1] == '1' && !vis[i][j + 1])
    {
        floodfill(i, j + 1, lim);
    }
    if (i > 0 && j > 0 && mat[i - 1][j - 1] == '1' && !vis[i - 1][j - 1])
    {
        floodfill(i - 1, j - 1, lim);
    }
    if (i < lim && j < lim && mat[i + 1][j + 1] == '1' && !vis[i + 1][j + 1])
    {
        floodfill(i + 1, j + 1, lim);
    }
    if (i > 0 && j < lim && mat[i - 1][j + 1] == '1' && !vis[i - 1][j + 1])
    {
        floodfill(i - 1, j + 1, lim);
    }
    if (i < lim && j > 0 && mat[i + 1][j - 1] == '1' && !vis[i + 1][j - 1])
    {
        floodfill(i + 1, j - 1, lim);
    }
}

int main()
{
    int n;
    int num = 0;
    while (cin >> n)
    {
        ++num;
        int cont = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat[i][j];
                vis[i][j] = false;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == '1' && !vis[i][j])
                {
                    cont++;
                    floodfill(i, j, n);
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n", num, cont);
    }
}