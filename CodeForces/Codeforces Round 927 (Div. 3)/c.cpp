#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> v(n), prefix(n + 1, 1);
        string s;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            prefix[i + 1] = v[i] * prefix[i];
        }
        cin >> s;
        for (int i = 0, l = 0, r = n - 1; i < n; i++)
        {
            cout << prefix[n] % m << " ";
            if (s[i] == 'L')
            {
                if (v[l] != 0)
                {
                    prefix[n] /= v[l];
                }
                l++;
            }
            else if (s[i] == 'R')
            {
                if (v[r] != 0)
                {
                    prefix[n] /= v[r];
                }
                r--;
            }
        }
        cout << endl;
    }
}