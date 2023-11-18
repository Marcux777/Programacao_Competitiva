#include <bits/stdc++.h>

using namespace std;

void completa(vector<string> &mat, int x, int y)
{
    if (mat[x][y] == '>')
    {
        for (int i = y + 1; i < mat[x].size() && (mat[x][i] == '.' || mat[x][i] == '!'); i++)
        {
            mat[x][i] = '!';
        }
    }
    if (mat[x][y] == '<')
    {
        for (int i = y - 1; i >= 0 && (mat[x][i] == '.' || mat[x][i] == '!'); i--)
        {
            mat[x][i] = '!';
        }
    }
    if (mat[x][y] == '^')
    {
        for (int i = x - 1; i >= 0 && (mat[i][y] == '.' || mat[i][y] == '!'); i--)
        {
            mat[i][y] = '!';
        }
    }
    if (mat[x][y] == 'v')
    {
        for (int i = x + 1; i < mat.size() && (mat[i][y] == '.' || mat[i][y] == '!'); i++)
        {
            mat[i][y] = '!';
        }
    }
}

bool isValid(const vector<string> &matrix, int row, int col)
{
    int numRows = matrix.size();
    int numCols = matrix[0].size();
    return (row >= 0 && row < numRows && col >= 0 && col < numCols &&
    (matrix[row][col] == '.' || matrix[row][col] == 'G'));
}

int bfs(const vector<string> &matrix, pair<int, int> S, pair<int, int> G)
{
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};
    int numRows = matrix.size();
    int numCols = matrix[0].size();

    vector<vector<int>> distance(numRows, vector<int>(numCols, -1));
    vector<vector<bool>> vis(numRows, vector<bool>(numCols, false));
    queue<pair<int, int>> q;

    q.push(S);
    distance[S.first][S.second] = 0;
    vis[S.first][S.second] = true;

    while (!q.empty())
    {
        pair<int, int> pos = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newRow = pos.first + dx[i];
            int newCol = pos.second + dy[i];

            if (isValid(matrix, newRow, newCol) && distance[newRow][newCol] == -1)
            {
                q.push({newRow, newCol});
                distance[newRow][newCol] = distance[pos.first][pos.second] + 1;
                vis[newRow][newCol] = true;
            }
        }
    }

    return distance[G.first][G.second];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> mat(n);
    for (int i = 0; i < n; i++)
    {
        cin >> mat[i];
    }
    pair<int, int> dest, end;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == '<' || mat[i][j] == '^' || mat[i][j] == 'v' || mat[i][j] == '>')
            {
                completa(mat, i, j);
            }
            if (mat[i][j] == 'S')
            {
                dest = {i, j};
            }
            if (mat[i][j] == 'G')
            {
                end = {i, j};
            }
        }
    }
    /*for(auto i : mat){
        cout << i << endl;
    }*/
    cout << bfs(mat, dest, end) << endl;
}