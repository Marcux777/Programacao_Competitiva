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
    long long int B, P, M;

    while (cin >> B >> P >> M){
        cout << binpow(B, P, M) << endl;
    }
    return 0;
}

