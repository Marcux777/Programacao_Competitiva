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
    int t; cin >> t;
    int n, m, k, c;
    while(t--){
        cin >> n >> m >> k;
        vector<int> a(n), b(m);
        c = 0;
        for(auto &i : a) cin >> i;
        for(auto &j : b) cin >> j;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i] + b[j] <= k) c++;
            }
        }
        cout << c << endl;
    }
}