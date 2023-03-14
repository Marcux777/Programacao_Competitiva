#include <bits/stdc++.h>

using namespace std;

bool vis[401][401];
char ff[401][401];
int cont, resp;

void floodfill(int i, int j, int maxh, int maxl){
    if(ff[i][j] == 'C'){
        cont++;
    }
    vis[i][j] = true;
    if(i < maxh && (ff[i+1][j] == 'C' || (ff[i+1][j] == 'P' && cont == 0)) && !vis[i+1][j]){
        floodfill(i+1, j, maxh, maxl);
    }
    if(i > 0 && (ff[i-1][j] == 'C' || (ff[i+1][j] == 'P' && cont == 0)) && !vis[i-1][j]){
        floodfill(i-1, j, maxh, maxl);
    }
    if(j < maxl && (ff[i][j+1] == 'C' || (ff[i+1][j] == 'P' && cont == 0)) && !vis[i][j+1]){
        floodfill(i, j+1, maxh, maxl);
    }
    
    if(j > 0 && (ff[i][j-1] == 'C' || (ff[i+1][j] == 'P' && cont == 0)) && !vis[i][j-1]){
        floodfill(i, j-1, maxh, maxl);
    }

}

int main(){
    int h, l;
    resp = 0;
    cin >> h >> l;
    for(int i = 0; i < h; i++){
        for(int j = 0; j< l; j++){
            cin >> ff[i][j];
            vis[i][j] = false;
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < l; j++){
            if(ff[i][j] == 'C'){
                if(!vis[i][j]){
                    cont = 0;
                    floodfill(i, j, h, l);
                }
            }
            if(cont > resp){
                resp = cont;
            }
        }
    }
    cout << resp << endl;
}