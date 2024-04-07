#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    map<int, priority_queue<int>> mp;
    int m = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        m = max(m, v[i]);
        mp[v[i]].push(i);
    }

    while (q--)
    {
        int op, k, a, b;
        cin >> op;

        if (op == 1)
        {
            cin >> k;
            if (mp.count(k))
            {
                continue;
            }
            if (k > m)
            {
                m = k;
                mp[k].push(n);
                v.push_back(k);
                n++;
            }
            else
            {
                auto it = mp.upper_bound(k);
                if (it != mp.begin())
                {
                    it--;
                    mp[k].push(it->second.top());
                    v[it->second.top()] = k;
                    it->second.pop();
                }
            }
        }
        if (op == 2)
        {
            int count = 0;
            cin >> a >> b;
            for (auto it = mp.lower_bound(a); it != mp.end() && it->first <= b; it++)
            {
                count += it->second.size();
            }
            cout << count << endl;
        }
    }

    return 0;
}
