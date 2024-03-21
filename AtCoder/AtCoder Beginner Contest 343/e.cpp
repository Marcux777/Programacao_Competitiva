#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define inf LLONG_MAX
#define Ninf LLONG_MIN
#define mod 1000000007

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    while (Q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int p, x;
            cin >> p >> x;
            A[p - 1] = x; // 0-indexed
        }
        else
        {
            int l, r;
            cin >> l >> r;
            vector<int> B(A.begin() + l - 1, A.begin() + r); // 0-indexed
            sort(B.begin(), B.end());
            int max_val = B.back();
            int second_max = *(lower_bound(B.begin(), B.end(), max_val) - 1);
            cout << count(B.begin(), B.end(), second_max) << '\n';
        }
    }
}