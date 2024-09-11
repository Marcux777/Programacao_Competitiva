#include <bits/stdc++.h>
using namespace std;

int main() {
    int value; cin >> value;
    vector<int> dp(value + 1, INT_MAX);
    dp[0] = 0; // Caso base: não são necessárias operações para alcançar 0.

    for (int i = 1; i <= value; ++i) {
        int aux = i;
        while (aux > 0) {
            int digit = aux % 10;
            if (digit > 0) {
                dp[i] = min(dp[i], dp[i - digit] + 1);
            }
            aux /= 10;
        }
    }

    cout << dp[value] << endl;
}