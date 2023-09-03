#include <iostream>

using namespace std;

long long binpow(long long a, long long b, long long n)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % n;
        a = (a * a) % n;
        b >>= 1;
    }
    return res;
}

int main()
{
    // freopen("saida.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c;
    cin >> c;
    while (c--)
    {
        long long int x, y, n;
        cin >> x >> y >> n;
        cout << binpow(x, y, n) << endl;
    }
    cin >> c;
}