#include <bits/stdc++.h>

using namespace std;

const int M = 2e5 + 10;

int memo[30][M];

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> v(n+1);
	for(int i = 1; i <= n; i++){
		cin >> v[i];
		memo[0][i] = v[i];
		
	}
	
	for(int i = 0; i < 29; i++){
		for(int v = 1; v <= n; v++){
			int u = memo[i][v];
			memo[i+1][v] = memo[i][u];
		}
	}
	
	while(q--){
		int x, k;
		cin >> x >> k;
		for(int i = 29; i >=0; i--){
			if((1 << i) <= k){
				x = memo[i][x];
				k -= (1 << i);
			}
		}
		cout << x << endl;
	}
}
