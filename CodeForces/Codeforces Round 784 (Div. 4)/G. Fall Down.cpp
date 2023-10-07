#include <bits/stdc++.h>

using namespace std;

void ff(vector<vector<char>>&m, int x, int y){
	if(x < 0 || y < 0 || x >= (int)m.size() || y >= (int)m[0].size()){
		return;
	}
	if(x+1 < (int)m.size() && m[x+1][y] == '*'){
		ff(m, x+1, y);
	}
	if(x+1 < (int)m.size() && m[x+1][y] == '.'){
		m[x][y] = '.';
		m[x+1][y] = '*';
		ff(m, x+1, y);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>mapa(n, vector<char>(m));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> mapa[i][j];
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(mapa[i][j] == '*'){
					ff(mapa, i, j);
				}
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0;j < m; j++){
				cout << mapa[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
}