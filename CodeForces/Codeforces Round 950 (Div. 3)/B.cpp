#include <bits/stdc++.h>

using namespace std;


void solve() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, f, k;
        cin >> n >> f >> k;
        
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        int value = a[f - 1];
        sort(a.rbegin(), a.rend());
        
        int cnt = count(a.begin(), a.end(), value);
        int f_ocorrenc = find(a.begin(), a.end(), value) - a.begin();
        int l_ocorrenc = f_ocorrenc + cnt - 1;
        
        if (f_ocorrenc < k) {
            if (l_ocorrenc < k) {
                cout << "YES" << endl;
            } else {
                cout << "MAYBE" << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}