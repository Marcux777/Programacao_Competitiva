#include <iostream>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

long long int pow(long int b, long int exp, long int mod)
{
    long long int ret = 1;

    while (exp > 0)
    {
        if ((exp & 1) > 0)
            ret = (ret * b) % mod;
        b = (b * b) % mod;
        exp >>= 1;
    }

    return ret;
}

long long int coeficienteBinomial(int n, int r)
{
    if (r > n)
        return 0;

    if (n - r > r)
        r = n - r;

    long long int SPF[n + 1];

    for (int i = 1; i <= n; i++)
        SPF[i] = i;

    for (int i = 4; i <= n; i += 2)
        SPF[i] = 2;

    for (int i = 3; i * i < n + 1; i += 2)
    {

        if (SPF[i] == i)
        {
            for (int j = i * i; j < n + 1; j += i)
                if (SPF[j] == j)
                {
                    SPF[j] = i;
                }
        }
    }
    map<long long int, long long int> prime_pow;

    for (int i = r + 1; i < n + 1; i++)
    {

        int t = i;

        while (t > 1)
        {
            if (!prime_pow[SPF[t]])
            {
                prime_pow[SPF[t]] = 1;
            }
            else
                prime_pow[SPF[t]]++;
            t /= SPF[t];
        }
    }

    for (int i = 1; i < n - r + 1; i++)
    {
        int t = i;

        while (t > 1)
        {
            prime_pow[SPF[t]]--;
            t /= SPF[t];
        }
    }

    long long int ans = 1, mod = 1000000007;

    for (auto it : prime_pow)

        ans = (ans * pow(it.first, prime_pow[it.first], mod)) % mod;
    return ans;
}
/*
soma = 100
mid = x
mid*100/soma = x
*/


long double calculaProb(vector<long long int> &v)
{
    int mid = v[v.size()/2];
    long long int soma = 0;
    for(auto i : v){
        soma+=i;
    }
    return (long double)mid*100.0/soma;
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    n--;
    vector<long long int> v(n+1);
    for (int i = 0; i <= n; i++)
    {
        v[i] = coeficienteBinomial(n, i);
    }
    for(auto i : v){
        cout << i << endl;
    }
    cout << fixed << setprecision(2);
    cout << calculaProb(v) << endl;
}