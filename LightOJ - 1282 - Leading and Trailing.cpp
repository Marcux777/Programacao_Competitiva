#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    //freopen("saida.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long int x, y, mod = 1000;
        cin >> x >> y;
        double N = log10(x * 1.0) * y;
        N -= floor(N);
        N = pow(10, N);
        N *= 100;
        printf ("Case %d: %03d %03d\n", i+1, (int)N, binpow(x, y, mod));
    }
}