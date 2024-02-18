#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define endl '\n'

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

long long f(long long N, long long M, long long K) {
    long long L = lcm(N, M);

    long long low = 1, high = 1e18;
    while (low+1 < high) {
        long long mid = (low + high) / 2;
        if ((mid / N) + (mid / M) - (mid / L) < K)
            low = mid;
        else
            high = mid;
    }

    return low;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;

    cout << f(n, m, k) << endl;
    
}