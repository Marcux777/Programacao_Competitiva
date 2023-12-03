#include <bits/stdc++.h>

using namespace std;

vector<bool>vis;
set<char>fim;

void dfs(vector<vector<pair<int, set<char>>>>&graph, int s, int e){
    vis[s] = true;
    if(s == e) return;
    for(auto v : graph[s]){
        if(!vis[v.first]){
            for(auto it : v.second){
                if(fim.find(it) == fim.end()){ 
                    //Não tem essa letra, 
                    //bora adicionar no fim
                    fim.insert(it);
                }
            }
            for(auto it : fim){
                if(v.second.find(it) == v.second.end()){ //Se essa letra tá no set fim e não tá no set do grafo, vou remover essa letra
                    fim.erase(it);
                }
            }
            dfs(graph, v.first, e);
        }
    }
}

int main() {
    int n;
    while(cin >> n && n){
        fim.clear();
        vis.resize(n+1, false);
        vector<vector<pair<int, set<char>>> >graph(n+1);
        int x, y;
        string emps;
        while(cin >> x >> y >> emps && (x || y)){
            set<char>aux;
            for(auto i : emps) aux.insert(i);
            graph[x].push_back({y, aux});
        }
        while(cin >> x >> y && (x || y)){
            dfs(graph, x, y);
            for(auto i : fim){
                cout << i;
            }
        }
        cout << endl;
    }
}
