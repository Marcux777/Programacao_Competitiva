#include <bits/stdc++.h>

using namespace std;

int lcs(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(2, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i % 2][j] = 1 + dp[(i - 1) % 2][j - 1];
                } else {
                    dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
                }
            }
        }

        return dp[m % 2][n];
    }

int main(){
    string a, b;
    while(getline(cin, a) && getline(cin, b)){
        cout << lcs(a, b) << endl;
    }
}