#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define inf LLONG_MAX
#define Ninf LLONG_MIN
#define mod 1000000007

long long NCR(int n, int r)
{
    if (r > n - r)
    {
        r = n - r;
    }
    long long result = 1;
    for (int i = 0; i < r; i++)
    {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s, aux;
    cin >> s;
    int ans = 0, res = 0;
    aux = s;
    map<char, int> mp;
    for (auto i : s)
    {
        if (mp.count(i))
            mp[i]++;
        else
            mp[i] = 1;
    }
    if (mp.size() == 1)
        cout << 1 << endl;
    else
    {
        for (auto i : mp)
        {
            for (auto j : mp)
            {
                if (i != j)
                    ans += i.second * j.second;
            }
            if (i.second > 1)
                res = 1;
        }
        cout << ans / 2 + res << endl;
    }
}