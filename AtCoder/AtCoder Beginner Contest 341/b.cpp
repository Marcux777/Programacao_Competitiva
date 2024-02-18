#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define endl '\n'

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vector<int> v(n+1), s(n), t(n);

    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    for(int i = 1; i < n; i++){
        cin >> s[i] >> t[i];
    }
    for(int i = 1; i < n; i++){
        if(v[i] >= s[i]){
            v[i] -= s[i];
            v[i+1] += t[i];
        }
    }
    cout << *max_element(v.begin(), v.end()) << endl;
}