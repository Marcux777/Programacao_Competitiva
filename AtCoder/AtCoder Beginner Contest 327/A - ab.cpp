#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    for (auto i = 0; i < s.size() - 1; i++)
    {
        if ((s[i] == 'a' && s[i + 1] == 'b') || (s[i + 1] == 'a' && s[i] == 'b'))
        {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
}