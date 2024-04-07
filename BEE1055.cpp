#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    vector<int> v, permute;
    int t, t1 = 1;
    cin >> t;
    while (t1 <= t)
    {
        long long int soma = 0;
        cin >> n;
        v = vector<int>(n);
        permute = vector<int>(n);
        for (auto &i : v)
            cin >> i;

        sort(v.begin(), v.end());
        int idx = 0;
        for (int i = 0, j = n - 1; i <= j; i++, j--)
        {
            permute[idx++] = v[i];
            permute[idx++] = v[j];
        }

        for (int i = 0; i < n - 1; i++)
        {
            soma += abs(permute[i] - permute[i + 1]);
        }
        cout << "Case " << t1 << ": " << soma << endl;
        t1++;
    }
}