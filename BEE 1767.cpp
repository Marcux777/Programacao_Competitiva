#include <bits/stdc++.h>

using namespace std;

vector<int> a, b;
vector<vector<int>> dp1, dp2;
int t, total;
map<int, int> sacos;

int f(int weight, int id){
    if(weight > 50) return 0;
    if(id >= t) return 0;
    if(dp1[id][weight] != -1) return dp1[id][weight];

    int e = f(weight, id+1);
    int x;
    if(weight + b[id] <= 50){
        int r = f(weight+b[id], id+1) + a[id];
        x = r - a[id] + b[id];
        e = max(e, r);
   }
    return dp1[id][weight] = e;
}

int main(){
    int n; cin >> n;
    while(n--){
        total = 0;
        cin >> t;
        a.resize(t);
        b.resize(t);
        dp1 = vector<vector<int>>(t, vector<int>(50, -1));
        dp2 = vector<vector<int>>(t, vector<int>(50, -1));
        for(int i = 0; i < t; i++){
            cin >> a[i] >> b[i];
            sacos[a[i]] = b[i];
        }
        cout << f(0, 0) << endl;
    }
}