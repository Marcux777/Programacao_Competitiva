#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ull k;
    cin >> n >> k;

    vector<pair<ull, ull>> intervals(n);
    for (int i = 0; i < n; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    ull left = 1, right = 2e18, ans = -1;
    while (left <= right) {
        ull mid = (left + right) / 2;
        ull views = 0;
        for (auto& interval : intervals) {
            if (interval.first <= mid) {
                views += (mid - interval.first) / interval.second + 1;
            }
        }
        if (views >= k) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}
