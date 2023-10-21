#include <bits/stdc++.h>

using namespace std;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << binpow(a, b) + binpow(b, a) << endl;
}