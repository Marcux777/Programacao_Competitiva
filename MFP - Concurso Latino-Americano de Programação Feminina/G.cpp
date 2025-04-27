#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s; cin >> s;
    string t, q;
    for(int i= 0; i<s.size();i++)
    {
        if(i%2 == 0)
            t += s[i];
        else
            q += s[i];
    }
    cout << t << endl;
    cout << q << endl;
}

int32_t main()
{
    int tt;
    tt = 1;
    while (tt --> 0)
        solve();
    return 0;
}
