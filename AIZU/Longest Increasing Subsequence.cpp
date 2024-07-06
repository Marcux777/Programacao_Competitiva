#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;

    vector<int> sub;
    for (int i = 0; i < n; i++)
    {
        if (sub.size() == 0 || sub[sub.size() - 1] < v[i])
        {
            sub.push_back(v[i]);
        }
        else
        {
            auto it = lower_bound(sub.begin(), sub.end(), v[i]);
            *it = v[i];
        }
    }
    cout <<  sub.size() << endl;
}