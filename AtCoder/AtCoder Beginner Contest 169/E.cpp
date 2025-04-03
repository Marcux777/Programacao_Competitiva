#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    if (N % 2 == 1) {
        // Mediana é o elemento do meio
        int low = A[N/2];
        int high = B[N/2];
        cout << high - low + 1 << endl;
    } else {
        // Mediana é a média dos dois elementos do meio
        int low1 = A[N/2 - 1];
        int low2 = A[N/2];
        int high1 = B[N/2 - 1];
        int high2 = B[N/2];
        // O menor valor possível é (low1 + low2)/2
        // O maior valor possível é (high1 + high2)/2
        // Número de valores distintos é (high1 + high2) - (low1 + low2) + 1
        cout << (high1 + high2) - (low1 + low2) + 1 << endl;
    }
    return 0;
}
