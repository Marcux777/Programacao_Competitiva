#include <bits/stdc++.h>

using namespace std;


int bfs(int s, int e){
	queue<pair<int, int>>q;
	unordered_set<int>visit;
	q.push({s,0});
	visit.insert(s);
	while(!q.empty()){
		int u = q.front().first;
		int dist = q.front().second;
		visit.insert(u);
		q.pop();
		if(u == e){
			return dist;
		}
		if(u - 1 > 0 && visit.find(u-1) == visit.end()){
			q.push({u-1, dist+1});
		}
		if(2*u < 100000 && visit.find(2*u) == visit.end()){
			q.push({2*u, dist+1});
		}
	}
	return -1;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    cin >> a >> b;
    cout << bfs(a, b) << endl;
    
}
