#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> pd;
vector<int> a, b;
int n, p;

int f(int id, int w){
    if(id >= n) return 0;
    if(w > p) return 0;
    if(pd[id][w] != -1) return pd[id][w];

    int c = f(id+1, w);
    if(a[id] + w <= p){
        int r = f(id+1, w+a[id]) + b[id];
        c = max(c, r);
    }
    return pd[id][w] = c;
}

int main(){
    cin >> n >> p;
    a.resize(n+1);
    b.resize(n+1);
    pd = vector<vector<int> >(n+1, vector<int>(n+1, -1));
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    cout << f(0, 0) << endl;
}