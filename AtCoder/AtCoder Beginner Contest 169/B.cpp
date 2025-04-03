#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<long long> A(N);
    bool has_zero = false;

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (A[i] == 0) has_zero = true;
    }

    if (has_zero) {
        cout << 0 << endl;
        return 0;
    }

    const long long LIMIT = 1e18;
    long long product = 1;

    for (int i = 0; i < N; ++i) {
        if (A[i] > LIMIT / product) {
            cout << -1 << endl;
            return 0;
        }
        product *= A[i];
    }

    if (product > LIMIT) {
        cout << -1 << endl;
    } else {
        cout << product << endl;
    }

    return 0;
}
