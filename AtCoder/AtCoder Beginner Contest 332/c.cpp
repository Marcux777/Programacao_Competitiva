#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define endl '\n'

signed main()
{
    ios::sync_with_stdio(true);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int count = 0;
    int a = m;
    int maxC = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '2')
        { // comptições
            count++;
        }
        else if (s[i] == '1')
        { // rolezinhos
            if (a <= 0)
            {
                count++;
            }
            a--;
        }
        else if (s[i] == '0')
        {
            maxC = max(maxC, count);
            count = 0;
            a = m;
        }
    }

    maxC = max(maxC, count);
    count = a = 0;
    cout << maxC << endl;
}