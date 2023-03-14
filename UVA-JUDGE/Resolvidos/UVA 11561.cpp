#include <bits/stdc++.h>

using namespace std;

char mapa[51][51];
bool vis[51][51];
int cont;

void floodfill(int i, int j, int liml, int limc){
	if(mapa[i][j] == 'G'){
		cont++;
	}
	vis[i][j] = true;
	if(mapa[i][j] == '#' || mapa[i][j+1] == 'T' || mapa[i+1][j] == 'T' || mapa[i][j-1] == 'T' || mapa[i-1][j] == 'T'){
		return;
	}
	if(i > 0 && (mapa[i-1][j] == '.' || mapa[i-1][j] == 'G') && !vis[i-1][j]){
		floodfill(i-1, j, liml, limc);
	}
	if(j > 0 && (mapa[i][j-1] == '.' || mapa[i][j-1] == 'G') && !vis[i][j-1]){
		floodfill(i, j-1, liml, limc);
	}
	if(i < liml && (mapa[i+1][j] == '.' || mapa[i+1][j] == 'G') && !vis[i+1][j]){
		floodfill(i+1, j, liml, limc);
	}
	if(j < limc && (mapa[i][j+1] == '.' || mapa[i][j+1] == 'G') && !vis[i][j+1]){
		floodfill(i, j+1, liml, limc);
	}
}

int main(){
	int m, n;
	while(cin >> m >> n){
		cont = 0;
		memset(vis, false, sizeof(vis));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> mapa[i][j];
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(mapa[i][j] == 'P'){
					floodfill(i, j, n, m);
				}
			}
		}
		cout << cont << endl;
	}
}
