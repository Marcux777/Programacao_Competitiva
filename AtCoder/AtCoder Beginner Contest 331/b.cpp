#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define endl '\n'
#define INF 10000000000
#define mod 32768

int N, s, m, l;
vector<int> DP;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> s >> m >> l;
    int ans = INF;
    for (int a = 0; a <= 100; a++)
    {
        for (int b = 0; b <= 100; b++)
        {
            for (int c = 0; c <= 100; c++)
            {
                if (a * 6 + b * 8 + c * 12 >= N)
                {
                    ans = min(ans, a * s + b * m + c * l);
                }
            }
        }
    }
    cout << ans << endl;
}