#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long a, b, C;
    cin >> a >> b >> C;
    int L = 60;
    int c = __builtin_popcountll(C);
    for (int n00 = 0; n00 <= L - c; n00++) {
        for (int n01 = 0; n01 <= c; n01++) {
            int n10 = c - n01;
            int n11 = L - c - n00;
            if (n10 + n11 != a) continue;
            if (n01 + n11 != b) continue;
            long long X = 0, Y = 0;
            for (int i = 0; i < L; i++) {
                if (C >> i & 1) {
                    if (n10-- > 0) {
                        X |= 1LL << i;
                    } else {
                        Y |= 1LL << i;
                    }
                } else {
                    if (n11-- > 0) {
                        X |= 1LL << i;
                        Y |= 1LL << i;
                    }
                }
            }
            cout << X << " " << Y << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}