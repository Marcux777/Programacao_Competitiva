#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> mapa;
int linhas, colunas;
int costa;

bool isWater(int x, int y)
{
    return (x < 0 || y < 0 || x >= linhas || y >= colunas || mapa[x][y] == '.');
}

bool isInside(int x, int y)
{
    return (isWater(x + 1, y) || isWater(x - 1, y) || isWater(x, y + 1) || isWater(x, y - 1));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> linhas >> colunas;

    mapa.resize(linhas, vector<char>(colunas));

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            cin >> mapa[i][j];
        }
    }

    costa = 0;

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            if (mapa[i][j] == '#' && isInside(i, j))
            {
                costa++;
            }
        }
    }

    cout << costa << endl;

    return 0;
}
