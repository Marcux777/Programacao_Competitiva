#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int linha = grid.size();
        int col = grid[0].size();
        int cont = 0;
        for (int i = 0; i < linha; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 0) {
                    if (floodfill(grid, linha, col, i, j)) {
                        cont++;
                    }
                }
            }
        }
        return cont;
    }

    bool floodfill(vector<vector<int>>& map, int maxLinha, int maxCol, int x, int y) {
        if (x < 0 || y < 0 || x >= maxLinha || y >= maxCol) {
            return false;
        }
        if (map[x][y] != 0) {
            return true;
        }
        map[x][y] = 1;
        bool a = floodfill(map, maxLinha, maxCol, x + 1, y);
        bool b = floodfill(map, maxLinha, maxCol, x - 1, y);
        bool c = floodfill(map, maxLinha, maxCol, x, y + 1);
        bool d = floodfill(map, maxLinha, maxCol, x, y - 1);
        return a && b && c && d;
    }
};

int main() {
    Solution solution;

    // Criação da matriz de inteiros
    vector<vector<int>> grid = {
        {1, 1, 1, 1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 1, 0},
        {1, 0, 1, 0, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 0}
    };

    // Chamada da função closedIsland
    int result = solution.closedIsland(grid);

    // Imprime o número de ilhas fechadas na matriz
    cout << "Número de ilhas fechadas: " << result << endl;

    return 0;
}
