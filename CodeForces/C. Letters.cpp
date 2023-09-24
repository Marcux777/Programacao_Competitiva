#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0) {
            a[i] += a[i - 1];
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < m; i++) {
        int dormitory = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        long long room = b[i] - (dormitory > 0 ? a[dormitory - 1] : 0);
        cout << dormitory + 1 << " " << room << endl;
    }
    return 0;
}
