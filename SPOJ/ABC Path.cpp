#include<bits/stdc++.h>
using namespace std;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int R, C;
vector<string> grid;
vector<vector<int>> visited;

int dfs(int x, int y) {
    if(x<0 || x>=R || y<0 || y>=C) return 0;
    if(visited[x][y]) return 0;

    visited[x][y] = 1;
    int ans = 1;

    for(int i=0; i<8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0 && nx<R && ny>=0 && ny<C && grid[nx][ny] == grid[x][y] + 1)
            ans = max(ans, 1 + dfs(nx, ny));
    }

    return ans;
}

int main() {
    int t = 0;
    while(cin >> R >> C && R && C) {
        t++;
        grid.resize(R);
        visited.assign(R, vector<int>(C));

        for(int i=0; i<R; i++) cin >> grid[i];

        int ans = 0;
        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                if(grid[i][j] == 'A') {
                    visited.assign(R, vector<int>(C));
                    ans = max(ans, dfs(i, j));
                }
            }
        }

        cout << "Case " << t << ": " << ans << endl;
    }
}
