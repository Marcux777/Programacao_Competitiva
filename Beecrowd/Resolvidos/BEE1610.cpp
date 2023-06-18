#include <iostream>
#include <vector>

using namespace std;

bool hasLoop(const vector<vector<int>> &adjList, vector<bool> &visited, vector<bool> &stack, int v)
{
    visited[v] = true;
    stack[v] = true;

    for (int neighbor : adjList[v])
    {
        if (!visited[neighbor])
        {
            if (hasLoop(adjList, visited, stack, neighbor))
            {
                return true;
            }
        }
        else
        {
            if (stack[neighbor])
            {
                return true;
            }
        }
    }

    stack[v] = false;
    return false;
}

bool hasDocumentLoop(const vector<vector<int>> &adjList, int n)
{
    vector<bool> visited(n + 1, false);
    vector<bool> stack(n + 1, false);

    for (int v = 1; v <= n; ++v)
    {
        if (!visited[v])
        {
            if (hasLoop(adjList, visited, stack, v))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    //freopen("saida.txt", "w", stdout);
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> adjList(n + 1);

        for (int i = 0; i < m; ++i)
        {
            int a, b;
            cin >> a >> b; // dependência entre documentos
            adjList[a].push_back(b);
        }

        if (hasDocumentLoop(adjList, n))
        {
            cout << "SIM" << endl;
        }
        else
        {
            cout << "NAO" << endl;
        }
    }

    return 0;
}
