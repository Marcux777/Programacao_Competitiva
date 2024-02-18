#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define endl '\n'

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M), X(N+1, 0);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];

    for (int i = N-1; i >= 0; i--) {
        if (i < N-1) A[i] += A[i+1];
    }

    for (int i = 0; i < M; i++) {
        int b = B[i];
        X[b] += b;
        X[b+1] -= b;
        int l = b, r = N;
        while (r-l > 1) {
            int mid = (l+r)/2;
            if (A[mid] > X[b]) l = mid;
            else r = mid;
        }
        X[r] += X[b];
        X[b] = 0;
    }

    for (int i = 0; i < N; i++) {
        if (i > 0) X[i] += X[i-1];
        cout << X[i] << " ";
    }
    cout << "\n";


}