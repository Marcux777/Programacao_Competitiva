#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, l, d;
    cin >> n >> l >> d;

    int cof = ceil((double)n * d / 1000);

    int litros = ceil((double)cof / l) * l;

    cout << litros << endl;

    return 0;
}
