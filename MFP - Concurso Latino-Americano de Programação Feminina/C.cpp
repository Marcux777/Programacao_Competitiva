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
    int k1, k2, k3;
    cin >> k1 >> k2 >> k3;
    if(k1 == k2) cout << k3 << endl;
    else if (k1 == k3) cout << k2 << endl;
    else cout << k1 << endl;
}

int32_t main()
{
    int tt;
    tt = 1;
    cin >> tt;
    while (tt --> 0)
        solve();
    return 0;
}
