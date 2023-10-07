#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cin >> k;
    queue<int>q;
    for (int i = 0; i < k; i++)
    {
        int l, r;
        cin >> l >> r;
        auto it = upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l);
        q.push(it);
    }
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}