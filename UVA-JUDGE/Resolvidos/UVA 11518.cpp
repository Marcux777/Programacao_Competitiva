#include <bits/stdc++.h>

using namespace std;

vector <int> adj[10001];
bool vis[10001];
int cont;

void inicia(){
	for(int i = 0; i < 10001; i++){
		vis[i] = false;
		adj[i].clear();
	}
	cont = 0;
}

void dfs(int u){
	vis[u] = true;
	
	for(int i = 0; i < adj[u].size(); i++){
		int k = adj[u][i];
		if(!vis[k]){
			dfs(k);
		}
	}
	
}
int main(){
	int t, m, l, x, y, z, n;
	bool flag = false;
	cin >> t;
	while(t--){
			inicia();
			if(flag){
				cout << endl;
			}
			cin >> n >> m >> l;
			for(int i = 0; i < m; i++){
				cin >> x >> y;
				adj[x].push_back(y);
				//adj[y].push_back(x);
			}
			cin >> z;
			vis[z] = true;
			for(int i = 0; i < n; i++){
				if(!vis[i]){
					
					dfs(i);
					cont++;
				}
			}
			flag = true;
			cout << cont << endl;
		}
}


