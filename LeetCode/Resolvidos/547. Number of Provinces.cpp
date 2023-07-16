#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<bool> vis;

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int cont = 0;
        vis.resize(isConnected.size());
        zera();
        for (int i = 0; i < isConnected.size(); i++)
        {
            for (int j = 0; j < isConnected[0].size(); j++)
            {
                if (isConnected[i][j] && !vis[i])
                {
                    cont++;
                    dfs(isConnected, i);
                }
            }
        }
        return cont;
    }

    void zera()
    {
        for (int i = 0; i < vis.size(); i++)
        {
            vis[i] = false;
        }
    }

    void dfs(vector<vector<int>> &V, int n)
    {
        vis[n] = true;

        for (int i = 0; i < V[n].size(); i++)
        {
            if (V[n][i] && !vis[i])
            {
                dfs(V, i);
            }
        }
    }
};

int main()
{
    Solution solution;

    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};

    int result = solution.findCircleNum(isConnected);

    cout << "Número de províncias: " << result << endl;

    return 0;
}
