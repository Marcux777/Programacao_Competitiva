#include <bits/stdc++.h>

using namespace std;

int main(){
    int h, r, x, y;
    cin >> h >> r >> x >> y;
    double ans = 0;
    if (fabsl(y - x) < 1e-18L) {
        ans = h / 2.0L;
    } else {
        long double sa = sqrtl(x), sw = sqrtl(y);
        ans = h * sa / (sa + sw);
        if (ans < 0) ans = 0;
        if (ans > h) ans = h;
    }
    cout << fixed << setprecision(10);
    cout << ans << endl;
}
