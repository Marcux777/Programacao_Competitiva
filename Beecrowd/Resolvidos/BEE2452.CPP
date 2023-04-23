#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k = 0, ans = 0, l, i, j, x, y, res = 0, p = 0;
    queue<int> pq;
    int a[100001];
    cin >> j >> y;
    for (i = 0; i < y; i++)
    {
        cin >> k;
        pq.push(k);
    }
    a[0] = 1;
    for (i = 1; i <= j; i++)
    {
        a[i] = 0;
    }
    l = i = y;
    k = 0;
    while (!pq.empty())
    {
        x = pq.front();
        res++;
        pq.pop();
        a[x] = 1;
        if (a[x - 1] == 0 and x - 1 > 0)
            pq.push(x - 1), k++, a[x - 1] = 1;
        if (a[x + 1] == 0 and x + 1 <= j)
            pq.push(x + 1), k++, a[x + 1] = 1;
        if (res == l)
        {
            l = k;
            k = 0;
            if (p != 0)
                ans++;
            res = 0;
            p++;
        }
    }
    cout << ans << endl;
    return 0;
}