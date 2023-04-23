#include <iostream>
#include <queue>
#include <utility>

using namespace std;

const int MAXN = 2000;

int n, m;
char img[MAXN][MAXN];
bool vis[MAXN][MAXN];

const int dx[] = {-1, 0, 1, 0}; // Deslocamentos no eixo x (horizontal)
const int dy[] = {0, -1, 0, 1}; // Deslocamentos no eixo y (vertical)

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true;
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj] && img[ni][nj] == '.')
            {
                q.push({ni, nj});
                vis[ni][nj] = true;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("saida.txt", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> img[i][j];
            vis[i][j] = false;
        }
    }
    int cont = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (img[i][j] == '.' && !vis[i][j])
            {
                bfs(i, j);
                cont++;
            }
        }
    }
    cout << cont << endl;
}
