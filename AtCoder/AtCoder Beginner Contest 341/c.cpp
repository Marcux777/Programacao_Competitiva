#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define endl '\n'

string s;
int N, w, h;
vector<string> grid;

bool dfs(int x, int y, int i){
    if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == '#'){
        return false;
    }
    for(int j = i; j < N; j++){
        if(s[j] == 'L'){
            return dfs(x, y-1, j+1);
        }
        if(s[j] == 'R'){
            return dfs(x, y+1, j+1);
        }
        if(s[j] == 'U'){
            return dfs(x-1, y, j+1);
        }
        if(s[j] == 'D'){
            return dfs(x+1, y, j+1);
        }
    }
    return true;
    
}


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> h >> w >> N;
    cin >> s;
    grid = vector<string>(h);
    for (int i = 0; i < h; i++)
    {
        cin >> grid[i];
    }
    int c = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(grid[i][j] == '.'){
                if(dfs(i, j, 0)){
                    c++;
                }
            }
        }
    }
    
    cout << c << endl;
}