#include <bits/stdc++.h>

using namespace std;

#define int long long int

signed main(){
    int n, q; 
    cin >> n >> q;
    set<int> s;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        s.insert(x);
    }

    vector<int> v(s.begin(), s.end());
    while(q--){
        int x; 
        cin >> x;
        auto l = lower_bound(v.begin(), v.end(), x) - v.begin();
        auto r = upper_bound(v.begin(), v.end(), x) - v.begin();

        cout << l << " " << v.size() - r << endl;
    }
}