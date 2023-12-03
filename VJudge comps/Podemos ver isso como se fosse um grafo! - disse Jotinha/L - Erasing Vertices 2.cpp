#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<long long int> v(n + 1);
    vector<vector<int>> graph(n + 1);
    set<pair<long long int, int>> st;
    vector<long long int> sum(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }


    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        sum[x] += v[y];
        sum[y] += v[x];
    }
    for (int i = 1; i <= n; i++)
        st.insert({sum[i], i});

    long long int ans = 0LL;

    while (st.size())
    {
        auto i = st.begin()->second;
        auto w = st.begin()->first;
        st.erase(st.begin());
        ans = max(ans, w);
        for (auto a : graph[i])
        {
            if (!v[a])
                continue;
            st.erase(st.find({sum[a], a}));
            sum[a] -= v[i];
            st.insert({sum[a], a});
        }
        v[i] = 0;
    }
    cout << ans << endl;
}