#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define endl '\n'
#define INF 1e9 + 7


int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int bfs(vector<string>& grid, pair<int, int> start1, pair<int, int> start2) {
    int n = grid.size();
    vector<vector<vector<int>>> dist(n, vector<vector<int>>(n, vector<int>(n, -1)));
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({start1, start2});
    dist[start1.first][start1.second][start2.first] = 0;
    while (!q.empty()) {
        pair<int, int> cur1 = q.front().first, cur2 = q.front().second; q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx1 = cur1.first + dx[i], ny1 = cur1.second + dy[i];
            int nx2 = cur2.first + dx[i], ny2 = cur2.second + dy[i];
            if (nx1 < 0 || nx1 >= n || ny1 < 0 || ny1 >= n || grid[nx1][ny1] == '#') {
                nx1 = cur1.first; ny1 = cur1.second;
            }
            if (nx2 < 0 || nx2 >= n || ny2 < 0 || ny2 >= n || grid[nx2][ny2] == '#') {
                nx2 = cur2.first; ny2 = cur2.second;
            }
            if (dist[nx1][ny1][nx2] == -1) {
                dist[nx1][ny1][nx2] = dist[cur1.first][cur1.second][cur2.first] + 1;
                q.push({{nx1, ny1}, {nx2, ny2}});
            }
        }
    }
    return dist[start2.first][start2.second][start1.first];
}


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<string>v(n);
    vector<pair<int, int>>players;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        for(int j = 0; j < n; j++){
            if(v[i][j] == 'P') 
                players.push_back({i, j});
        }
    }

    cout << bfs(v, players[0], players[1]) << endl;

    
}