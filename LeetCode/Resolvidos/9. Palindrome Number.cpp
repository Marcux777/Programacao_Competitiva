#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }
        long long int num = 0, compara = x;
        while (x)
        {
            num = num * 10;
            num += x % 10;
            x = x / 10;
        }
        return num == compara;
    }
};

int main()
{
    Solution a;
    int num;
    while (cin >> num)
    {
        if (a.isPalindrome(num))
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }
}