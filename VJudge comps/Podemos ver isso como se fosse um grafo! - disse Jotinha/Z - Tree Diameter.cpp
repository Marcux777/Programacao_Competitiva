#include <bits/stdc++.h>
 
using namespace std;
 
int x;
 
void dfsUtil(int node, int count, vector<bool>& visited,
				int& maxCount, vector<vector<int>> &adj)
{
	visited[node] = true;
	count++;
	for (auto i = adj[node].begin(); i != adj[node].end(); ++i) {
		if (!visited[*i]) {
			if (count >= maxCount) {
				maxCount = count;
				x = *i;
			}
			dfsUtil(*i, count, visited, maxCount, adj);
		}
	}
}
 
void dfs(int node, int n, vector<vector<int>> &adj, int& maxCount)
{
	vector<bool> visited(n+1, false);
	int count = 0;
 
 
	dfsUtil(node, count + 1, visited, maxCount, adj);
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;cin >> n;
    vector<vector<int>>graph(n+1);
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int maxCount = INT_MIN;
 
	dfs(1, n, graph, maxCount);
 
	dfs(x, n, graph, maxCount);
 
    (maxCount != INT_MIN) ? cout << maxCount-1 << endl : cout << 0 << endl;
}