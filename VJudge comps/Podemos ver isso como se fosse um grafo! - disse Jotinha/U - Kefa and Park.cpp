#include <bits/stdc++.h>

using namespace std;

vector<int> gatinho;
int cont = 0;

void dfs(int u, vector<vector<int>>&graph, vector<bool>&vis, int m, int sumCat){
	vis[u] = true;
	if(sumCat > m){
		return;
	}
	bool ok = false;
	for(auto v : graph[u]){
		if(!vis[v]){
			gatinho[v] ? dfs(v, graph, vis, m, sumCat+1) : dfs(v, graph, vis, m, 0);
			ok = true;
		}
	}
	if(!ok){
		cont++;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>>graph(n+1);
	vector<bool> vis(n+1, false);
	gatinho.resize(n+1);
	for(int i = 1; i <= n; i++){
		cin >> gatinho[i];
	}
	for(int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	cont = 0;
	dfs(1, graph, vis, m, gatinho[1]);
	cout << cont << endl;
}
