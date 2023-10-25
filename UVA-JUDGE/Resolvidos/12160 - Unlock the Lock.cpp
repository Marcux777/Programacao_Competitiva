#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("saida.txt", "w", stdout);
    int L, U, R, RV[10], dist[10000], cs = 1;
    while (cin >> L >> U >> R, L || U || R) {
        for (int i = 0; i < R; i++) cin >> RV[i];
        memset(dist, -1, sizeof dist);
        dist[L] = 0;
        queue<int> q;
        q.push(L);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int i = 0; i < R; i++) {
                int v = (u + RV[i]) % 10000;
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        cout << "Case " << cs++ << ": ";
        if (dist[U] != -1) cout << dist[U] << "\n";
        else cout << "Permanently Locked\n";
    }
    return 0;
}
