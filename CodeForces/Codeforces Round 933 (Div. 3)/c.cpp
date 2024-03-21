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
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int count = 0;
        for (int i = 0; i < n;)
        {
            if (s.substr(i, 3) == "pie" || s.substr(i, 3) == "map")
            {
                count++;
                i += 3;
            }
            else
            {
                i++;
            }
        }

        cout << count << endl;
    }
}