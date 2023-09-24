#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    int lanterns[n];
    for (int i = 0; i < n; i++) {
        cin >> lanterns[i];
    }
    sort(lanterns, lanterns + n);
    double max_distance = max(lanterns[0], l - lanterns[n - 1]);
    for (int i = 1; i < n; i++) {
        max_distance = max(max_distance, (lanterns[i] - lanterns[i - 1]) / 2.0);
    }
    cout << fixed << setprecision(10) << max_distance << endl;
    return 0;
}
