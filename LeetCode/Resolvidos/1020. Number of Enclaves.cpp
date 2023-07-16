#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution
{
public:
    bool vis[500][500];
    int cont;

    int numEnclaves(vector<vector<int>> &grid)
    {
        memset(vis, false, sizeof(vis));
        int linha = grid.size();
        int col = grid[0].size();
        cont = 0;
        for (int i = 0; i < linha; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (i == 0 || j == 0 || (i == linha - 1) || (j == col - 1))
                {
                    if (grid[i][j] == 1)
                    {
                        floodfillVisit(grid, linha, col, i, j);
                    }
                }
            }
        }
        for (int i = 0; i < linha; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                {
                    cont++;
                }
            }
        }
        return cont;
    }

    void floodfillVisit(vector<vector<int>> &map, int limLinha, int limCol, int x, int y)
    {
        if (x < 0 || y < 0 || x >= limLinha || y >= limCol || vis[x][y] || map[x][y] == 0)
        {
            return;
        }
        vis[x][y] = true;
        floodfillVisit(map, limLinha, limCol, x - 1, y);
        floodfillVisit(map, limLinha, limCol, x + 1, y);
        floodfillVisit(map, limLinha, limCol, x, y - 1);
        floodfillVisit(map, limLinha, limCol, x, y + 1);
    }
};

int main()
{
    Solution solution;

    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 1, 1}};

    int result = solution.numEnclaves(grid);

    cout << "Número de enclaves: " << result << endl;

    return 0;
}
