#include <bits/stdc++.h>

using namespace std;

void dfs(vector<string>&v, vector<vector<bool>>&vis, int x, int y, int lin, int col){
    if(x < 0 || y < 0 || x >= lin || y >= col || vis[x][y] || v[x][y] != '#'){
        return;
    }
    vis[x][y] = true;
    
    dfs(v, vis, x-1, y, lin, col);
    dfs(v, vis, x+1, y, lin, col);
    dfs(v, vis, x, y-1, lin, col);
    dfs(v, vis, x, y+1, lin, col);
    dfs(v, vis, x-1, y-1, lin, col);
    dfs(v, vis, x-1, y+1, lin, col);
    dfs(v, vis, x+1, y-1, lin, col);
    dfs(v, vis, x+1, y+1, lin, col);

}

int main(){
    int h, w;
    cin >> h >> w;
    vector<string>v(h);
    vector<vector<bool>>vis(h, vector<bool>(w, false));
    for(int i = 0; i < h; i++){
        cin >> v[i];
    }
    int cont = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(v[i][j] == '#' && !vis[i][j]){
                cont++;
                dfs(v, vis, i, j, h, w);
            }
        }
    }
    cout << cont << endl;
    return 0;

}