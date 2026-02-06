#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin >> T)) return 0;
    while (T--) {
        int l, r;
        cin >> l >> r; // em D1, l = 0
        long long pw = 1;
        while (pw < r) pw = (pw << 1) | 1; // pw = 2^k - 1 >= r
        vector<int> a(r + 1, 0);
        unordered_set<int> S;
        S.reserve((r - l + 1) * 2);
        for (int x = l; x <= r; ++x) S.insert(x);

        long long ans = 0;
        for (int i = r; i >= l; --i) {
            while (!S.count((int)(pw - i))) pw >>= 1; // desce bloco até existir o par
            int j = (int)(pw - i);
            a[i] = j;           // a[i] acompanha b_i = i
            ans += (i | j);
            S.erase(j);
        }
        cout << ans << "\n";
        for (int i = l; i <= r; ++i) {
            cout << a[i] << (i == r ? '\n' : ' ');
        }
    }
    return 0;
}
