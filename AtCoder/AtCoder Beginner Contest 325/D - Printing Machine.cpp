#include <bits/stdc++.h>

using namespace std;

#define int long long int

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<pair<long long, long long>> TD(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> TD[i].first >> TD[i].second;
        TD[i].second += TD[i].first;
    }

    sort(TD.begin(), TD.end());

    priority_queue<long long, vector<long long>, greater<long long>> queue;
    int it = 0;
    int productsPrinted = 0;
    for (long long i = 0;; i++)
    {
        if (queue.empty())
        {
            if (it == N)
                break;
            i = TD[it].first;
        }
        while (it < N and TD[it].first == i)
        {
            queue.push(TD[it++].second);
        }
        while (!queue.empty() and queue.top() < i)
            queue.pop();
        if (!queue.empty())
        {
            queue.pop();
            ++productsPrinted;
        }
    }

    cout << productsPrinted << endl;

    return 0;
}