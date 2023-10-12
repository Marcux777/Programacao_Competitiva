#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int dx[] = {-2, -2, 2, 2, -1, -1, 1, 1};
const int dy[] = {-1, 1, -1, 1, -2, 2, -2, 2};

int bfs(int x1, int y1, int x2, int y2)
{
    int dis[9][9];
    memset(dis, 0, sizeof dis);
    queue<pair<int, int>> q;
    q.push({x1, y1});
    dis[x1][y1] = 0;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if (nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8 && dis[nx][ny] == 0)
            {
                q.push({nx, ny});
                dis[nx][ny] = dis[p.first][p.second] + 1;
                if (nx == x2 && ny == y2)
                {
                    return dis[nx][ny];
                }
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    while (cin >> a >> b)
    {
        if (a == b)
        {
            cout << "To get from " << a << " to " << b << " takes " << 0 << " knight moves." << endl;
        }
        else
        {
            int x1 = a[0] - 'a' + 1;
            int y1 = a[1] - '0';
            int x2 = b[0] - 'a' + 1;
            int y2 = b[1] - '0';
            cout << "To get from " << a << " to " << b << " takes " << bfs(x1, y1, x2, y2) << " knight moves." << endl;
        }
    }
    return 0;
}