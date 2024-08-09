#include <bits/stdc++.h>

using namespace std;

#define int long long int

int n, m;
vector<int> a, b;
vector<vector<int>> knap;


int f(int id, int w){
    if(id == n) return 0;
    if(w == m) return 0;
    if(knap[id][w] != -1) return knap[id][w];

    int a = f(id+1, w);
    if(w + b[id] <= m){
        int r = f(id+1, w+b[id]) + a[id];
        a = max(a, r);
    }

    return knap[id][w] = a;

}

signed main(){
    int n, m; cin >> n >> m;
    a = b = vector<int>(n);
    knap = vector<vector<int>>(n+1, vector<int>(m+1, -1));
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    cout << f(0, 0) << endl;
}