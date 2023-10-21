#include <bits/stdc++.h>

using namespace std;
int cont;
int maxCont;

void dfs(string &v, int x, int d){
    if(x < 0 || x >= (int)v.size() || v[x] == '0'){
        return;
    }
    cont++;
    cout << x << " " << d << " " << cont << endl;
    if(x == v.size()-1){
        maxCont = min(maxCont, cont);
        return;
    }
    for(int i = 1; i <= d; i++){
        cout << "entrou" << endl;
        dfs(v, x + i, d);
    }

}

int main()
{
    int n, d;
    cin>>n >> d;
    string v;
    cin >> v;
    cont = 0;
    maxCont = INT_MAX;
    dfs(v, 0, d);
    (maxCont == INT_MAX) ? cout << -1 : cout << maxCont;
    cout << endl;
}