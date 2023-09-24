#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        long long int n, k;
        cin >> n >> k;
        long long int r = (((n + k-1)/ k * k) + n - 1) / n;
        cout << r << endl;
    }
}
