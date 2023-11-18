#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define vi vector<int>

map<char, int> mp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != s[i - 1])
        {
            l = 1;
        }
        else
        {
            l++;
        }
        mp[s[i]] = max(mp[s[i]], l);
    }
    long long sum = 0;
    for (auto it : mp)
    {
        sum += it.second;
    }
    cout << sum << endl;
}