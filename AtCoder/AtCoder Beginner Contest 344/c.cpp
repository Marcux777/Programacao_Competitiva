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
    int n;
    vector<int> a, b, c, x;
    cin >> n;
    a.resize(n);
    for (auto &i : a)
        cin >> i;
    cin >> n;
    b.resize(n);
    for (auto &i : b)
        cin >> i;
    cin >> n;
    c.resize(n);
    for (auto &i : c)
        cin >> i;
    cin >> n;
    x.resize(n);
    for (auto &i : x)
        cin >> i;

    int ans = -1;

    unordered_set<int> st;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            st.insert(a[i] + b[j]);
        }
    }

    for (int i = 0; i < x.size(); i++)
    {
        bool found = false;
        for (int j = 0; j < c.size(); j++)
        {
            if (st.count(x[i] - c[j]))
            {
                found = true;
                break;
            }
        }
        cout << (found ? "Yes" : "No") << '\n';
    }
}