#include <bits/stdc++.h>

using namespace std;

#define int long long int

signed main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> bases;
    for (int i = 0; i < N; i++)
    {
        int W, X;
        cin >> W >> X;
        bases.push_back({X, W});
        bases.push_back({X + 24, W});
    }
    sort(bases.begin(), bases.end());

    vector<int> prefix(2*N + 1, 0);
    for (int i = 0; i < 2*N; i++)
    {
        prefix[i + 1] = prefix[i] + bases[i].second;
    }

    int l = 0, r = 0;
    int resposta = 0;
    while (r < 2*N)
    {
        while (bases[r].first - bases[l].first >= 9)
        {
            l++;
        }
        resposta = max(resposta, prefix[r + 1] - prefix[l]);
        r++;
    }
    cout << resposta << endl;

    return 0;
}
