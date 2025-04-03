#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;

    if(N == 1) {
        cout << 0 << endl;
        return 0;
    }

    map<ll, int> factors;
    ll temp = N;

    // Fatoração em primos
    for(ll i = 2; i*i <= temp; i++) {
        while(temp % i == 0) {
            factors[i]++;
            temp /= i;
        }
    }
    if(temp > 1) factors[temp]++;

    int res = 0;
    for(auto [p, e] : factors) {
        int k = 1;
        while(k*(k+1)/2 <= e) {
            k++;
        }
        res += k-1;
    }

    cout << res << endl;
    return 0;
}
