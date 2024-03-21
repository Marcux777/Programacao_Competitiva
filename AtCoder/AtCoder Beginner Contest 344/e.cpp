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
    cin >> n;
    list<int> a;
    unordered_map<int, list<int>::iterator> pos;

    for (int i = 0, val; i < n; ++i)
    {
        cin >> val;
        a.push_back(val);
        pos[val] = prev(a.end());
    }

    cin >> q;
    for (int i = 0, t, x, y; i < q; ++i)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> x >> y;
            auto it = pos[x];
            pos[y] = a.insert(next(it), y);
        }
        else if (t == 2)
        {
            cin >> x;
            a.erase(pos[x]);
            pos.erase(x);
        }
    }

    for (int val : a)
    {
        cout << val << " ";
    }
    cout << endl;
}