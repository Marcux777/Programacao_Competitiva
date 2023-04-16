#include <iostream>
#include "vector"

using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
            return 0;
        int lo = 1, hi = x;
        while (true)
        {
            int mid = lo + (hi - lo) / 2;
            if (mid > x / mid)
            {
                hi = mid - 1;
            }
            else
            {
                if ((mid + 1) > x / (mid + 1))
                {
                    return mid;
                }
                lo = mid + 1;
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    for (int num : nums)
    {
        cout << "Sqrt(" << num << ") = " << s.mySqrt(num) << endl;
    }
    return 0;
}
