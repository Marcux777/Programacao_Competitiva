#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define inf LLONG_MAX
#define Ninf LLONG_MIN
#define mod 1000000007

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    int n;
    while (t--)
    {
        cin >> n;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;
        for (int i = 1; i < n - 1; i++)
        {
            if (v[i] > 0 && v[i - 1] > 0 && v[i + 1] > 0)
            {
                int m = min(min(v[i - 1], 2 * v[i]), v[i + 1]);
                v[i - 1] -= m;
                v[i] -= 2 * m;
                v[i + 1] -= m;
            }
        }
        bool r = 0;
        for (auto i : v)
        {
            r = i != 0;
            if (r)
                break;
        }
        cout << (r ? "NO" : "YES") << endl;
    }
}