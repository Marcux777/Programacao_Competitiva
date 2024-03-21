#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define endl '\n'

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    vector<int> p(n);
    for(auto &i : p) cin >> i;

    int q; cin >> q;

    while(q--){
        int a, b, frente = -1;
        cin >> a >> b;
        for(auto i : p){
            if(i == a && frente == -1){
                frente = a;
            }else{
                if(i == b && frente == -1){
                    frente = b;
                }
            }
        }
        cout << frente << endl;
    }
    
}