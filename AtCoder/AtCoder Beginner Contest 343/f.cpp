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

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int p, x;
            cin >> p >> x;
            a[p - 1] = x;
        }
        else
        {
            int l, r;
            cin >> l >> r;
            vector<int> B(a.begin() + l - 1, a.begin() + r);
            sort(B.begin(), B.end());
            int max_val = B.back();
            int second_max = *(lower_bound(B.begin(), B.end(), max_val) - 1);
            cout << count(B.begin(), B.end(), second_max) << '\n';
        }
    }
}