#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        if (num < 2)
            return true;
        long lo = 2, hi = num / 2, mid;
        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            long sq = mid * mid;
            if (sq == num)
            {
                return true;
            }
            else if (sq > num)
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    int num = 16;
    cout << s.isPerfectSquare(num) << endl;
    num = 14;
    cout << s.isPerfectSquare(num) << endl;
    num = 121;
    cout << s.isPerfectSquare(num) << endl;
    num = 2147483647;
    cout << s.isPerfectSquare(num) << endl;
    return 0;
}
