#include <bits/stdc++.h>

using namespace std;

#define int long long int

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    vector<int>d(2*n);
    for(int i = 0; i < n; i++){
        cin >> d[i];
        d[i] %= a+b;
        d[n+i] = d[i] + a + b;
    }
    sort(d.begin(), d.end());
    bool r = false;
    for(int i = 0; i < n; i++){
        int c = lower_bound(d.begin(), d.end(), d[i]+a) - d.begin();
        r |= c == n+i;
    }
    cout << (r ? "Yes" : "No") << endl;
}