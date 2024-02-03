#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, Q[10], A[10], B[10];

bool check(ll x) {
    ll need = 0;
    for (int i = 0; i < N; ++i) {
        need += max(0LL, A[i] * x - Q[i]);
        if (need > B[i] * x) return false;
    }
    return true;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> Q[i];
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    ll lo = 0, hi = 1e9;
    while (hi - lo > 1) {
        ll mid = (lo + hi) / 2;
        if (check(mid)) lo = mid;
        else hi = mid;
    }

    cout << lo << endl;
    return 0;
}
