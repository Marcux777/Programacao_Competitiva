#include <iostream>

using namespace std;

char imagem[500][500];
int grid[500][500];

void to_bin(int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int position = 3;
            int n = (imagem[i][j] >= '0' and imagem[i][j] <= '9') ? imagem[i][j] - '0' : imagem[i][j] - 'a' + 10;

            while (n)
            {
                grid[i][(j << 2) + position] = (n & 1);

                n >>= 1;
                --position;
            }
        }
    }
}

int main()
{
    int h, w;
    while (cin >> h >> w && h && w)
    {
        for (int i = 0; i < h; i++)
        {
            cin >> imagem[i];
        }
        to_bin(h, w);
    }
}