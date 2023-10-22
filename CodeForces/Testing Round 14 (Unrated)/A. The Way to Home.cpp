#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    string v;
    cin >> v;
    vector<int> dist(n, INT_MAX);
    queue<int> q;
    dist[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 1; i <= d; i++) {
            if (x + i < n && v[x + i] == '1' && dist[x] + 1 < dist[x + i]) {
                dist[x + i] = dist[x] + 1;
                q.push(x + i);
            }
        }
    }
    (dist[n - 1] == INT_MAX) ? cout << -1 : cout << dist[n - 1];
    cout << endl;
}
