#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define endl '\n'

signed main(){
    int n, s, k;
    cin >> n >> s >> k;
    int total = 0, x, y;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        total += x*y;
    }
    if(total < s) cout << total + k << endl;
    else cout << total << endl;
}