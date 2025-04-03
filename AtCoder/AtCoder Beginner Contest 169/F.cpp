#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    int N, S;
    cin >> N >> S;
    vector<int> A(N);
    for (int &a : A) cin >> a;

    vector<vector<long long>> dp(N+1, vector<long long>(S+1, 0));
    dp[0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int s = 0; s <= S; s++) {
            // Opção 1: Não incluir o elemento em T
            dp[i+1][s] = (dp[i+1][s] + dp[i][s]) % MOD;

            // Opção 2: Incluir em T mas não no subconjunto que soma S
            dp[i+1][s] = (dp[i+1][s] + dp[i][s]) % MOD;

            // Opção 3: Incluir em T e no subconjunto que soma S
            if (s + A[i] <= S) {
                dp[i+1][s + A[i]] = (dp[i+1][s + A[i]] + dp[i][s]) % MOD;
            }
        }
    }

    cout << dp[N][S] % MOD << endl;
    return 0;
}
