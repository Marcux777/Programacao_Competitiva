#include <bits/stdc++.h>

using namespace std;

#define inf 4.611686e+18

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	//freopen("saida.txt", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		int n, k, a, b;
		cin >> n >> k >> a >> b;
		vector<int> x(n+1), y(n+1);
		for(int i = 0; i < n; i++){
			cin >> x[i+1] >> y[i+1];
		}
		long long resp = llabs(x[a] - x[b]) + llabs(y[a] - y[b]);
		long long MiniA, MiniB;
		MiniA = MiniB = inf;
		for(int i = 1; i <= k; i++){
			MiniA = min(MiniA, llabs(x[a] - x[i]) + llabs(y[a] - y[i]));
			MiniB = min(MiniB, llabs(x[b] - x[i]) + llabs(y[b] - y[i])); 
		}
		cout << min(resp, MiniA + MiniB) << endl;
	}
}