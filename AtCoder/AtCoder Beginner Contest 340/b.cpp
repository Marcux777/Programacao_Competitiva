#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define endl '\n'

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, c, x,k;
    cin >> t;
    deque<int> v;
    while(t--){
        cin >> c;
        if(c == 1){
            cin >> x;
            v.push_back(x);
        }else{
            cin >> k;
            cout << v[v.size()- k] << endl;
        }
    }
}