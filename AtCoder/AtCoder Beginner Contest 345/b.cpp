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
    int x; cin >> x;
    int ans;
    if(x > 0)
        ans = (x - 1)/10+1;
    else
        ans = x / 10;
    cout << ans << endl;
}