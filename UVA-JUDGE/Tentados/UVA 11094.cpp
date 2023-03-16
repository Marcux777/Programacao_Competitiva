#include <bits/stdc++.h>

using namespace std;

char mat[21][21];
char quem;
bool vis[21][21];
int cont, aux;

void floodfill(int i, int j, int maxi, int maxj){
    vis[i][j] = true;
    aux++;
    if(i > 0 && mat[i-1][j] == quem && !vis[i-1][j]){
        floodfill(i-1, j, maxi, maxj);
    }
    if(i < maxi && mat[i+1][j] == quem && !vis[i+1][j]){
        floodfill(i+1, j, maxi, maxj);
    }
    if(mat[i][(j-1+n)%n] == quem && !vis[i][j-1]){
        floodfill(i, ((j-1+n)%n), maxi, maxj);
    }
    if(mat[i][(j+1)%n] == quem && !vis[i][j+1]){
        floodfill(i, ((j+1)%n), maxi, maxj);
    }
}
int main(){
    int m, n, x, y;
    while(cin >> m >> n){
        cont = 0;
        memset(vis, false, sizeof(vis));
        getchar();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
            //getchar();
        }
        cin >> x >> y;
        quem = mat[x][y];

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] != quem){
                    vis[i][j] = true;
                }
            }
        }
        floodfill(x,y,m,n);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j]){
                    aux = 0;
                    floodfill(i, j, m, n);
                    cont = max(cont, aux);
                }
                
            }
        }
        cout << cont << endl;
        
    }
}