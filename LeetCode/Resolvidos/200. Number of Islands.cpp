#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int cont = 0;
        int col = grid[0].size();
        int linha = grid.size();
        for (int i = 0; i < linha; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == '1')
                {
                    cont++;
                    floodfill(grid, linha, col, i, j);
                }
            }
        }
        return cont;
    }

    void floodfill(vector<vector<char>> &mat, int limMax, int colMax, int x, int y)
    {
        if (x < 0 || y < 0 || x >= limMax || y >= colMax || mat[x][y] != '1')
        {
            return;
        }
        mat[x][y] = 'v';
        floodfill(mat, limMax, colMax, x + 1, y);
        floodfill(mat, limMax, colMax, x - 1, y);
        floodfill(mat, limMax, colMax, x, y + 1);
        floodfill(mat, limMax, colMax, x, y - 1);
    }
};

int main()
{
    Solution solution;

    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    int result = solution.numIslands(grid);

    cout << "Número de ilhas: " << result << endl;

    return 0;
}
