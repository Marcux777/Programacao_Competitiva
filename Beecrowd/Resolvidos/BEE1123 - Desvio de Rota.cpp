#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX

vector<int> rota;
vector<vector<pair<int, int>>> grafo;
vector<int> dist;
priority_queue<int> q;


int dijkstra(int s, int e){
    dist[s] = 0;
    q.push(s);
    while(!q.empty()){
        int u = q.top();
        q.pop();
        for(auto edge : grafo[u]){
            int v = edge.first;
            int w = edge.second;
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                q.push(v);
            }
        }
    }
    return dist[e];
}

int main (){
    int n, m, c, k;
    while (cin >> n >> m >> c >> k && (n||m||c||k)){
        grafo.resize(n);
        dist.assign(n, INF);
        rota.resize(c);
        for(int i = 0; i < c; i++){
            rota[i] = i;
        }
        for(int i = 0; i < m; i++){
            int u, v, p;
            cin >> u >> v >> p;
            if(u >= c && v >= c){
                grafo[u].push_back({v, p});
                grafo[v].push_back({u, p});
            }
            if(u >= c && v < c) grafo[u].push_back({v, p});
            if(u < c && v >= c) grafo[v].push_back({u, p});
            if(u < c && v < c && abs(u-v) == 1){
                grafo[u].push_back({v, p});
                grafo[v].push_back({u, p});
            }
        }
        cout << dijkstra(k, c-1) << endl;
    }
    return 0;
}
