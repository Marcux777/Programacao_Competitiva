#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    vector<bool> vis;
    set<int> fim;

    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        vis.resize(graph.size(), false);
        for (int i = 0; i < graph.size(); i++)
        {
            if (!vis[i])
            {
                dfs(graph, i);
            }
        }
        return vector<int>(fim.begin(), fim.end());
    }

    void dfs(vector<vector<int>> &g, int x)
    {
        vis[x] = true;
        for (int vizinho : g[x])
        {
            if (!vis[vizinho])
            {
                dfs(g, vizinho);
            }
            else if (fim.find(vizinho) != fim.end())
            {
                fim.insert(x);
            }
            else
            {
                return;
            }
        }
    }
};

int main()
{
    Solution solution;

    // Exemplo de chamada da função eventualSafeNodes

    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};

    vector<int> result = solution.eventualSafeNodes(graph);

    cout << "Nós eventualmente seguros: ";
    for (int node : result)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
