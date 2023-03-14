#include <iostream>
#include <cmath>
using namespace std;

int main() {
    //freopen("saida.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        cout << static_cast<long long>((-1 + sqrt(1 + 8*n)) / 2) << endl;
    }
    return 0;
}
