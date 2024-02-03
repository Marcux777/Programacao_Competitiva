#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int l, col;
    cin >> l >> col;
    vector<vector<int>> gridA(l, vector<int>(col));
    vector<vector<int>> gridB(l, vector<int>(col));
    map<int, pair<int, int>> posA, posB;

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < col; j++) {
            cin >> gridA[i][j];
            posA[gridA[i][j]] = {i, j};
        }
    }

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < col; j++) {
            cin >> gridB[i][j];
            posB[gridB[i][j]] = {i, j};
        }
    }

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < col; j++) {
            if (posA.find(gridB[i][j]) == posA.end()) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    int r = 0;

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            if (posA[gridB[i][0]].first != i) {
                swap(gridA[posA[gridB[i][0]].first], gridA[i]);
                r += abs(posA[gridB[i][0]].first - i);
                break;
            }
        }
    }

    for (int j = 0; j < col; j++) {
        for (int k = 0; k < col; k++) {
            if (posA[gridB[0][j]].second != j) {
                for (int i = 0; i < l; i++) {
                    swap(gridA[i][posA[gridB[0][j]].second], gridA[i][j]);
                }
                r += abs(posA[gridB[0][j]].second - j);
                break;
            }
        }
    }

    cout << r << endl;
    return 0;
}
