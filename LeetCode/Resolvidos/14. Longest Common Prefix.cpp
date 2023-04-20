#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
        {
            return "";
        }

        string prefix = "";
        for (int i = 0; i < strs[0].length(); i++)
        {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++)
            {
                if (i >= strs[j].length() || strs[j][i] != c)
                {
                    return prefix;
                }
            }
            prefix += c;
        }

        return prefix;
    }
};

int main()
{
    Solution x;
    int n;
    vector<string> str;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            string a;
            cin >> a;
            str.push_back(a);
        }
        cout << x.longestCommonPrefix(str) << endl;
    }
}