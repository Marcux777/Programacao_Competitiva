#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long ans = n * (n - 1) / 2 + 1;
        for (int i = 1; i <= n; i++) {
            ans += (n - i + 1) * (i - 1);
        }
        cout << ans << endl;
    }
    return 0;
}