#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (auto &i : v)
        cin >> i;

    vector<vector<pair<int, int>>> pred(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    pair<int, int> start, end;
    bool found = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'A')
            {
                start = {i, j};
                q.push(start);
                visited[i][j] = true;
            }
            if (v[i][j] == 'B')
                end = {i, j};
        }
    }

    int dirx[4] = {0, 0, 1, -1};
    int diry[4] = {1, -1, 0, 0};
    char dirChar[4] = {'R', 'L', 'D', 'U'};

    while (!q.empty() && !found)
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dirx[i];
            int ny = y + diry[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || v[nx][ny] == '#')
                continue;

            pred[nx][ny] = {x, y};
            visited[nx][ny] = true;
            q.push({nx, ny});

            if (v[nx][ny] == 'B')
            {
                found = true;
                break;
            }
        }
    }

    if (found)
    {
        cout << "YES" << endl;
        string path;
        for (pair<int, int> at = end; at != start; at = pred[at.first][at.second])
        {
            int px = pred[at.first][at.second].first;
            int py = pred[at.first][at.second].second;
            for (int i = 0; i < 4; i++)
            {
                if (px + dirx[i] == at.first && py + diry[i] == at.second)
                {
                    path += dirChar[i];
                    break;
                }
            }
        }
        reverse(path.begin(), path.end());
        cout << path.length() << endl;
        cout << path << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}