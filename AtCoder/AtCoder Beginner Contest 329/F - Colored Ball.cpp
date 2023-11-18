#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define vi vector<int>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    map<int, set<int>> mp;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        mp[i].insert(a);
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (mp[a].size() > mp[b].size())
        {
            swap(mp[a], mp[b]);
        }
        mp[b].insert(mp[a].begin(), mp[a].end());
        mp[a].clear();
        cout << mp[b].size() << endl;
    }
}