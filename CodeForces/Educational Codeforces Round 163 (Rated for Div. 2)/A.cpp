#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

string f(int n){
    string aux;
    for(int i = 0; i < n/2; i++){
        aux += 'A' + i;
        aux += 'A' + i;
    }
    return aux;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n%2 != 0) cout << "NO" << endl;
        else{
            cout << "YES" << endl;
            cout << f(n) << endl;
        }
    }
}