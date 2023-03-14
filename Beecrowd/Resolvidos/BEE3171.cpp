#include <bits/stdc++.h>

using namespace std;

vector <int> v[101];
bool vis[101] = {false};
int cont;

void dfs(int u){
    cont++;
    vis[u] = true;
    for(int i = 0; i < v[u].size(); i++){
        int k = v[u][i];
        if(!vis[k]){
            dfs(k);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, l, x, y;
    cont = 0;
    cin >> n >> l;
    for(int i = 0; i < l; i++){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int i = 1;
    if(!v[i].empty()){
        if(!vis[i]){
            dfs(i);
        }
    }
    //cout << cont << endl;
    if(cont == n){
        cout << "COMPLETO" << endl;
    }else{
        cout << "INCOMPLETO" << endl;
    }
}