#include <bits/stdc++.h>

using namespace std;

void floodfill(vector<vector<char>>&grid, int x, int y, int r, int c){
    if(x < 0 || y < 0 || x>=r || y>= c || grid[x][y] == '#'){
        return;
    }
    grid[x][y] = '#';
    floodfill(grid, x+1, y, r, c);
    floodfill(grid, x-1, y, r, c);
    floodfill(grid, x, y+1, r, c);
    floodfill(grid, x, y-1, r, c);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<char>>grid(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    int cont = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '.'){
                cont++;
                floodfill(grid, i, j, n, m);
            }
        }
    }
    cout << cont << endl;
}