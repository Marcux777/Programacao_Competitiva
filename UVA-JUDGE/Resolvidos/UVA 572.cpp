#include <bits/stdc++.h>

using namespace std;

char mat[100][100];
bool vis[100][100];
int cont;

void inicia(){
	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 100; j++){
			vis[i][j] = false;
		}
	}
	cont = 0;
}

void ff(int i, int j, int lin, int col){
	vis[i][j] = true;
	if(i > 0 && mat[i-1][j] == '@' && !vis[i-1][j]){
		ff(i-1, j, lin, col);
	}
	if(i < lin && mat[i+1][j] == '@' && !vis[i+1][j]){
		ff(i+1, j, lin, col);
	}
	if(j > 0 && mat[i][j-1] == '@' && !vis[i][j-1]){
		ff(i, j-1, lin, col);
	}
	if(j < col && mat[i][j+1] == '@' && !vis[i][j+1]){
		ff(i, j+1, lin, col);
	}
	if(i > 0 && j > 0 && mat[i-1][j-1] == '@' && !vis[i-1][j-1]){
		ff(i-1, j-1, lin, col);
	}
	if(i < lin && j < col && mat[i+1][j+1] == '@' && !vis[i+1][j+1]){
		ff(i+1, j+1, lin, col);
	}
	if(i > 0 && j < col && mat[i-1][j+1] == '@' && !vis[i-1][j+1]){
		ff(i-1, j+1, lin, col);
	}
	if(i < lin && j > 0 && mat[i+1][j-1] == '@' && !vis[i+1][j-1]){
		ff(i+1, j-1, lin, col);
	}
}

int main(){
	int m,n;
	cin >> m >> n;
	while(m){
		inicia();
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				cin >> mat[i][j];
			}
		}
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(mat[i][j] == '@'){
					if(!vis[i][j]){
						cont++;
						ff(i,j,m,n);
					}
				}
			}
		}
		cout << cont << endl;
		cin >> m >> n;
	}
}


