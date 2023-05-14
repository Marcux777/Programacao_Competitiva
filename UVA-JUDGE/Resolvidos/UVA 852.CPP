#include <bits/stdc++.h>

using namespace std;

char s[10][10];
bool vis[10][10];
bool tem_black, tem_white;
int cont;

void floodfill(int i, int j)
{
    if (i < 0 || j < 0 || i >= 9 || j >= 9 || vis[i][j])
    {
        return;
    }
    if (s[i][j] == '.')
    {
        cont++;
    }
    else
    {
        if (s[i][j] == 'O')
        {
            tem_black = true;
        }
        if (s[i][j] == 'X')
        {
            tem_white = true;
        }
        return;
    }
    vis[i][j] = true;
    floodfill(i - 1, j);
    floodfill(i + 1, j);
    floodfill(i, j - 1);
    floodfill(i, j + 1);
}

int main()
{
    // freopen("saida.txt", "w", stdout);
    int n;
    cin >> n;
    while (n--)
    {
        memset(vis, false, sizeof(vis));
        int totalB, totalW;
        totalB = totalW = 0;
        for (int i = 0; i < 9; i++)
        {
            scanf("%s", s[i]);
        }
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (s[i][j] == 'X')
                {
                    totalB++;
                }
                if (s[i][j] == 'O')
                {
                    totalW++;
                }

                if (s[i][j] == '.')
                {
                    tem_black = false;
                    tem_white = false;
                    cont = 0;
                    floodfill(i, j);
                    if (tem_black && !tem_white)
                    {
                        totalW += cont;
                    }
                    if (!tem_black && tem_white)
                    {
                        totalB += cont;
                    }
                }
            }
        }
        cout << "Black " << totalB << " "
             << "White " << totalW << endl;
    }
}