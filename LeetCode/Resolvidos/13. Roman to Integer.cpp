#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int soma = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i > 0 && mp[s[i]] > mp[s[i-1]]) {
                soma += mp[s[i]] - 2 * mp[s[i-1]];
            } else {
                soma += mp[s[i]];
            }
        }

        return soma;
    }
};

int main()
{
    Solution a;
    string str;
    while (cin >> str && str != "EOF")
    {
        cout << a.romanToInt(str) << endl;
    }
}