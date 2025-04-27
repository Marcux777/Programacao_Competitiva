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

class DSU
{
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n)
    {
        parent.assign(n, -1);
        rank.assign(n, 1);
    }

    int find(int i)
    {
        if (parent[i] == -1)
            return i;

        return parent[i] = find(parent[i]);
    }

    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
            }
            else if (rank[s1] > rank[s2])
            {
                parent[s2] = s1;
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += 1;
            }
        }
    }
};

void solve()
{
    int n, m; cin >> n >> m;
    int ruas = 0;
    DSU dsu(n + 1);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        if(dsu.find(u) != dsu.find(v)){
            dsu.unite(u, v);
        }else{
            ruas++;
        }
    }
    int conex = 0;
    for(int i = 1; i <= n; i++)
        if(dsu.find(i) == i)
            conex++;

    if(ruas == 0 && conex == 1){
        cout << "BOM\n";
    }else{
        cout << "RUIM ";
        cout << ruas << " " << conex-1 << endl;
    }   
}

int32_t main()
{
    int tt;
    tt = 1;
    while (tt --> 0)
        solve();
    return 0;
}
