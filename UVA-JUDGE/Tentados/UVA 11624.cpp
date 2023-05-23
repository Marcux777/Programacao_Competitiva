#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int n, m;
int cont;
vector<vector<char>>adj;
vector<vector<bool>> vis;

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
     // marca os vértices já visitados
    q.push({x, y});
    vis[x][y] = true;

    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if(i == n || j == m || i == -1 || j == -1){
            return;
        }
        cout << q.front().first << " " << q.front().second << endl;
        cont++;
        if((i - 1 >= 0 && i < n && j >= 0 && j < m) && !vis[i-1][j] && adj[i-1][j] == '.'){
            q.push({i-1, j});
            vis[i-1][j] = true;
        }
        if((i >= 0 && i + 1 < n && j >= 0 && j < m) && !vis[i+1][j] && adj[i+1][j] == '.'){
            q.push({i+1, j});
            vis[i+1][j] = true;
        }
        if((i >= 0 && i < n && j - 1 >= 0 && j < m) && !vis[i][j-1] && adj[i][j-1] == '.'){
            q.push({i, j-1});
            vis[i][j-1] = true;
        }
        if((i >= 0 && i < n && j > 0 && j < m) && !vis[i][j+1] && adj[i][j+1] == '.'){
            q.push({i, j+1});
            vis[i][j+1] = true;
        }
        
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        cont = 0;
        adj.resize(n, vector<char>(m));
        vis.resize(n, vector<bool>(m, false));
        char c;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> c;
                adj[i][j] = c;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (adj[i][j] == 'J')
                {
                    bfs(i, j);
                }
            }
        }
        cout << cont << endl;
    }
}