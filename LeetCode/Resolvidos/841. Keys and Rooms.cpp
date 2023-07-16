#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<bool> vis;

    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        vis.resize(rooms.size());
        dfs(rooms, 0);
        for (int i = 0; i < vis.size(); i++)
        {
            if (!vis[i])
            {
                return false;
            }
        }
        return true;
    }

    void dfs(vector<vector<int>> &g, int v)
    {
        vis[v] = true;
        for (auto u : g[v])
        {
            if (!vis[u])
            {
                dfs(g, u);
            }
        }
    }
};

int main()
{
    Solution solution;

    vector<vector<int>> rooms = {{1}, {2}, {3}, {}};

    bool result = solution.canVisitAllRooms(rooms);

    if (result)
    {
        cout << "É possível visitar todas as salas." << endl;
    }
    else
    {
        cout << "Não é possível visitar todas as salas." << endl;
    }

    return 0;
}
