#include <bits/stdc++.h>

using namespace std;

void solve() {
    int h, w, q;
    cin >> h >> w >> q;

    vector<set<int>> H(h);
    vector<set<int>> V(w);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            H[i].insert(j);
            V[j].insert(i);
        }
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;

        if (H[x].count(y)) {
            H[x].erase(y);
            V[y].erase(x);
        } else {
            auto itc = V[y].lower_bound(x);
            if (itc != V[y].begin()) {
                itc--;
                H[*itc].erase(y);
                V[y].erase(itc);
            }

            auto itb = V[y].upper_bound(x);
            if (itb != V[y].end()) {
                H[*itb].erase(y);
                V[y].erase(itb);
            }

            auto ite = H[x].lower_bound(y);
            if (ite != H[x].begin()) {
                ite--;
                V[*ite].erase(x);
                H[x].erase(ite);
            }

            auto itd = H[x].upper_bound(y);
            if (itd != H[x].end()) {
                V[*itd].erase(x);
                H[x].erase(itd);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < h; i++) {
        ans += H[i].size();
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    while (tt--) {
        solve();
    }

    return 0;
}