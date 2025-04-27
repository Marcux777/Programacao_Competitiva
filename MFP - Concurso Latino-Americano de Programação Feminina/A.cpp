#if defined(LOCAL) or not defined(LUOGU)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,unroll-loops")
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    ordered_set<pair<int,int>> os;
    for(int i = 0; i < n; i++)
        os.insert({a[i], i});

    for(int k = 1; k <= m; k++){
        cout << n - os.order_of_key({k, 0}) << " ";
    }
    cout << endl;
}

int32_t main()
{
    int tt;
    tt = 1;
    while (tt --> 0)
        solve();
    return 0;
}
