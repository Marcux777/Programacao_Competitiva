#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        vector<vector<int>> result;
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> can_reach_pacific(m, vector<bool>(n, false));
        vector<vector<bool>> can_reach_atlantic(m, vector<bool>(n, false));

        // Traverse from Pacific
        for (int i = 0; i < m; i++)
        {
            dfs(heights, can_reach_pacific, i, 0);
        }
        for (int j = 0; j < n; j++)
        {
            dfs(heights, can_reach_pacific, 0, j);
        }

        // Traverse from Atlantic
        for (int i = 0; i < m; i++)
        {
            dfs(heights, can_reach_atlantic, i, n - 1);
        }
        for (int j = 0; j < n; j++)
        {
            dfs(heights, can_reach_atlantic, m - 1, j);
        }

        // Find cells reachable from both oceans
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (can_reach_pacific[i][j] && can_reach_atlantic[i][j])
                {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

    void dfs(vector<vector<int>> &map, vector<vector<bool>> &vis, int x, int y)
    {
        vis[x][y] = true;
        int linha = map.size();
        int col = map[0].size();
        if (x > 0 && !vis[x - 1][y] && map[x - 1][y] >= map[x][y])
        {
            dfs(map, vis, x - 1, y);
        }
        if (x < linha - 1 && !vis[x + 1][y] && map[x + 1][y] >= map[x][y])
        {
            dfs(map, vis, x + 1, y);
        }
        if (y > 0 && !vis[x][y - 1] && map[x][y - 1] >= map[x][y])
        {
            dfs(map, vis, x, y - 1);
        }
        if (y < col - 1 && !vis[x][y + 1] && map[x][y + 1] >= map[x][y])
        {
            dfs(map, vis, x, y + 1);
        }
    }
};

int main()
{
    Solution solution;

    // Criação da matriz de inteiros
    vector<vector<int>> heights = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}};

    // Chamada da função pacificAtlantic
    vector<vector<int>> result = solution.pacificAtlantic(heights);

    // Imprime as células alcançáveis pelos dois oceanos
    cout << "Células alcançáveis por ambos os oceanos: " << endl;
    for (const auto &cell : result)
    {
        cout << "(" << cell[0] << ", " << cell[1] << ")" << endl;
    }

    return 0;
}
