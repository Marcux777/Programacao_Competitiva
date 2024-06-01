#include<bits/stdc++.h>
using namespace std;

const int MAXN = 16;
const int MAXS = 1 << MAXN;
int N, K, M, cnt[MAXS], dp[MAXS];
char str[MAXN+2];

int main() {
    scanf("%d%d%d", &N, &K, &M);
    for(int i = 1; i < (1 << N); i++) cnt[i] = cnt[i>>1] + (i&1);
    fill(dp, dp+(1<<N), 1);
    while(M--) {
        int mask = 0, c;
        scanf("%d%s", &c, str);
        while(c--) {
            int x;
            scanf("%d", &x);
            mask |= 1 << (x-1);
        }
        if(str[0] == 'o') {
            for(int i = 0; i < (1 << N); i++)
                if((i & mask) && cnt[i & mask] < K) dp[i] = 0;
        } else {
            for(int i = 0; i < (1 << N); i++)
                if(cnt[i & mask] >= K) dp[i] = 0;
        }
    }
    int ans = 0;
    for(int i = 0; i < (1 << N); i++) ans += dp[i];
    printf("%d\n", ans);
    return 0;
}