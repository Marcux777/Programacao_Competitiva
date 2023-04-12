#include <iostream>

using namespace std;

int cycleLength(int n) {
    int length = 1;
    while (n > 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
        length++;
    }
    return length;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("saida.txt", "w", stdout);
    int i, j;
    while (cin >> i >> j) {
        int maxCycle = 0;
        for (int n = min(i, j); n <= max(i, j); n++) {
            int currentCycle = cycleLength(n);
            maxCycle = max(maxCycle, currentCycle);
        }
        cout << i << ' ' << j << ' ' << maxCycle << endl;
    }
    return 0;
}
