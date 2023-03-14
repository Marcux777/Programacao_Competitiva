#include <bits/stdc++.h>
using namespace std;

bool mat[100][100] = {false};
bool vis[100];
char let[100];
int cont, tam;
int t;
char x, y;
int n = 1, v, a;

//Função que zera os arrays e variaveis
void zera(){
	cont = 0;
    tam = 0;
	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 100; j++){
			mat[i][j] = false;
		}
		vis[i] = false;
	}
}
void dfs(int n){
	vis[n] = true;
	int i;
    let[tam] = n;
    tam++;

	for(i = 0; i < v; i++){
		if(mat[n][i] && !vis[i]){
			dfs(i);
		}
	}
}
//ordena o vetor let
void ordena(char vetor[]) {
	int i, j;

	for(i = 0; i < tam; i++) {
		for(j = i; j < tam; j++) {
			if(vetor[i] > vetor[j]) {
                char aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
		}
	}
}

int main(){
	cin >> t;
	while(t--){
		zera();
		cin >> v >> a;
		for(int i = 0; i < a; i++){
			cin >> x >> y;
			mat[x-'a'][y-'a'] = true;
			mat[y-'a'][x-'a'] = true;
		}
        cout << "Case #" << n << ":"<<endl;
		n++;
        for(int i = 0; i < v; i++){
            if(!vis[i]){
                cont++;
                dfs(i);
                ordena(let);
                for(int j = 0; j < tam; j++){
                    cout << char(let[j] + 'a') << ",";
                }
                cout << endl;
            }
            tam = 0;
        }
        cout << cont << " connected components\n" << endl;
	}
}