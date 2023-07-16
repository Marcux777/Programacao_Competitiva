#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution
{
public:
    bool vis[50][50];
    int cont;

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int MaiorArea = 0;
        memset(vis, false, sizeof(vis));
        int linha = grid.size();
        int col = grid[0].size();
        for (int i = 0; i < linha; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                {
                    cont = 0;
                    floodfill(grid, linha, col, i, j);
                    if (cont > MaiorArea)
                    {
                        MaiorArea = cont;
                    }
                }
            }
        }
        return MaiorArea;
    }

    void floodfill(vector<vector<int>> &map, int maxlinha, int maxcol, int x, int y)
    {
        if (x < 0 || y < 0 || x >= maxlinha || y >= maxcol || vis[x][y] || map[x][y] == 0)
        {
            return;
        }
        if (map[x][y] == 1)
        {
            cont++;
            vis[x][y] = true;
        }

        floodfill(map, maxlinha, maxcol, x + 1, y);
        floodfill(map, maxlinha, maxcol, x - 1, y);
        floodfill(map, maxlinha, maxcol, x, y + 1);
        floodfill(map, maxlinha, maxcol, x, y - 1);
    }
};

int main()
{
    Solution solution;

    // Criação da matriz de inteiros
    vector<vector<int>> grid = {
        {0, 0, 1, 0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1},
        {0, 1, 0, 0, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    // Chamada da função maxAreaOfIsland
    int result = solution.maxAreaOfIsland(grid);

    // Imprime a maior área de uma ilha na matriz
    cout << "Maior área de uma ilha: " << result << endl;

    return 0;
}
