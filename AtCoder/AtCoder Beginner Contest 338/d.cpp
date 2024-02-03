#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define endl '\n'
#define INF 1e9 + 7

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> passeio(m);

    for(auto&i : passeio) cin >> i;

    vector<int> diff(m);
    int total = 0;
    for (int i = 0; i < m; i++) {
        diff[i] = (passeio[(i+1)%m] - passeio[i] + n) % n;
        if (diff[i] == 0) diff[i] = n;
        total += diff[i];
    }

    int max_diff = *max_element(diff.begin(), diff.end());

    int min_length = total - max_diff + min(diff[0], n - diff[0]);

    cout << min_length << endl;

}
