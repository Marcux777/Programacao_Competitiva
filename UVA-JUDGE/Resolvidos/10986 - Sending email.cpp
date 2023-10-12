#include <bits/stdc++.h>

using namespace std;

#define ll long long
typedef pair<ll, ll> pii;
const ll inf = INT_MAX;

ll pinto(vector<vector<pii>>&m, int a, int b){
	priority_queue<pii, vector<pii>, greater<pii>>pq;
	vector<ll>dist(m.size(), inf);
	pq.push({0,a});
	dist[a] = 0;
	while(!pq.empty()){
		ll u = pq.top().second;
		ll t = pq.top().first;
		pq.pop();
		for(auto i : m[u])
		{
			ll v = i.second;
			ll w = i.first;
			//cout << v <<" " << w  << " " << dist[v]<<endl;
			if(dist[v] > t+w){
				dist[v] = t+w;
				pq.push({dist[v], v});
			}
		}
	}
	return dist[b];
}

signed main(){
	int c;
	cin >> c;
	int ca = 0;
	while(c--){
		int m, n, s, t;
		cin >> n >> m >> s >> t;
		vector<vector<pii>>v(n);
		for(int i = 0; i < m; i++){
			int x,y;
			ll w;
			cin >> x >> y >> w;
			v[x].push_back({w, y});
			v[y].push_back({w, x});
		}
		printf("Case #%d: ", ++ca);
		pinto(v, s, t) != inf ? cout << pinto(v, s, t) << endl : cout << "unreachable" << endl;
	}
	
}
