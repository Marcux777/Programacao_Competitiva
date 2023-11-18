#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define vi vector<int>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    string s, t;
    cin >> s >> t;
    int j = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == t[j])
        {
            j++;
        }
        if (j == t.size())
        {
            break;
        }
    }
    if (j == t.size())
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}