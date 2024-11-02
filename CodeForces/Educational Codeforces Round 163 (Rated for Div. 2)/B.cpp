#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        queue<int> l;
        int n, x;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if (x >= 10)
            {
                for (auto it : to_string(x))
                {
                    if (it != '0')
                        l.push(it - '0');
                }
            }else{
                l.push(x);
            }
        }
        int ant = l.front();
        l.pop();
        while (l.size() && l.front() >= ant)
        {
            ant = l.front();
            l.pop();
        }
        cout << (l.empty() ? "YES" : "NO") << endl;
    }
}