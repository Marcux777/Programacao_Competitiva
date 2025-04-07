#include <bits/stdc++.h>

using namespace std;

#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0)


int check(int x){
    return x - (x/3) - (x/5) + (x/15);
}

signed main() {
    IOS;
    int n; cin >> n;
    int l = 1, r = 1e19;
    while(l < r){
        int m = l + (r - l) / 2;
        if(check(m) < n){
            l = m + 1;
        }else r = m;
    }
    cout << l << endl;
}
