#include <bits/stdc++.h>

using namespace std;

#define int long long int

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, Q, sum = 0;
    cin >> N >> Q;
    set<int> S;
    vector<int> A(N + 1, 0);
    for (int i = 0; i < Q; i++)
    {
        int x;
        cin >> x;

        if (S.count(x))
        {
            S.erase(x);
            A[x] += sum;
        }
        else
        {
            S.insert(x);
            A[x] -= sum;
        }
        sum += S.size();
    }
    for(auto i : S){
        A[i] += sum;
    }
    for (int i = 1; i <= N; i++)
    {
        cout << A[i] << " ";
    }
}