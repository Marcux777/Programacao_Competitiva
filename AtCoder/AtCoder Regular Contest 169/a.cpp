#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    long long N;
    cin >> N;
    vector<long long> A(25010 + 1), P(25010);
    vector<long long> deaph(25010 + 1), sum(25010 + 1);
    long long maxD = -1;
    for (long long i = 1; i <= N; ++i)
    {
        cin >> A[i];
    }
    for (long long i = 2; i <= N; ++i)
    {
        cin >> P[i];
        deaph[i] = deaph[P[i]] + 1;
        maxD = max(maxD, deaph[i]);
    }

    for (int i = 1; i <= N; i++)
    {
        sum[deaph[i]] += A[i];
    }
    for (int i = maxD; i >= 0; i--)
    {
        if (sum[i] > 0)
        {
            cout << "+" << endl;
            return 0;
        }
        else if (sum[i] < 0)
        {
            cout << "-" << endl;
            return 0;
        }
    }
    cout << 0 << endl;
}
