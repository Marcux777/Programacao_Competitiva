#include <bits/stdc++.h>
using namespace std;

int n,n2;
bool vis[26];
vector <int> vet[26];
string s;
int cont;

void inicia(){
	cont = 0;
	for(int i = 0; i < 26; i++){
		vis[i] = false;
		vet[i].clear();
	}
}
void dfs(int u){
	vis[u] = true;
	
	for(int i=0; i<vet[u].size(); i++){
		if(!vis[i]){
			dfs(i);
		}
	}
}

int main(){
	int t;
	cin >> t;
	bool fim=false;
	while(t--){
		inicia();
		if(fim)cout << endl;
		char let;
		cin >> let;
		cin.ignore();
		n = let - 'A';
		while(getline(cin,s) && s != "\0"){
			int x, y;
			x = s[0] - 'A';
			y = s[1] - 'A';
			vet[x].push_back(y);
			vet[y].push_back(x);
		}
		for(int i = 0; i <= n; i++){
			if(!vis[i]){
				dfs(i);
				cont++;
			}
		}
		fim=true;
		cout << cont << endl;
	}
	
	
}


