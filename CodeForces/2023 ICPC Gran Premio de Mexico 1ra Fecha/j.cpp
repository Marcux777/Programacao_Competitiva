#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    vector<int> prefix(n+1);
    for(auto &i: v) cin >> i;
    for(int i = 0; i < n-1; i++){
        prefix[i] = v[i] * v[i]
    }   

    while(q--){
        int a, b;
        cin >> a >> b;
        a--, b--;
        cout << grad[a][b] << endl;
    }
}