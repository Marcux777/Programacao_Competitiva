#include <iostream>
#include <vector>
using namespace std;

const int MAX = 500005;
int parent[MAX];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);  // Compressão de caminho
    }
    return parent[x];
}

void unite(int x, int y) {
    parent[find(x)] = find(y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    for (int i = 1; i < MAX; ++i) {
        parent[i] = i;
    }

    vector<int> a;

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            a.push_back(x);
        } else {
            int x, y;
            cin >> x >> y;
            if (x != y) {
                unite(x, y);
            }
        }
    }

    for (auto &x : a) {
        x = find(x);
    }

    for (auto x : a) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}