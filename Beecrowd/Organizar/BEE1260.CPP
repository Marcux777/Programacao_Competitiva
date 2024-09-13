#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;
vector<string> v;

bool comp(string a, string b)
{
    return a < b;
}

int main()
{
    int n, m;
    scanf("%d\n\n", &n);
    while (n--)
    {
        string str;
        m = 0;
        mp.clear();
        v.clear();
        while (getline(cin, str) && str.length())
        {
            if (!mp[str])
                v.push_back(str);
            mp[str]++;
            m++;
        }
        sort(v.begin(), v.end(), comp);
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " " << fixed << setprecision(4) << (double)mp[v[i]] / m * 100.0 << endl;
        if (n)
            cout << endl;
    }
    return 0;
}