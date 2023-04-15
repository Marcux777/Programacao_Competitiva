#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int lo = 0, hi = nums.size() - 1;
        int mid;
        while (hi - lo > 1)
        {
            int mid = (hi + lo) / 2;
            if (nums[mid] < target)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }
        if (nums[lo] == target)
        {
            return lo;
        }
        else if (nums[hi] == target)
        {
            return hi;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    Solution solucao;
    vector<int> nums = {-1, 0, 5};
    int target = 5;
    cout << solucao.search(nums, target);
    return 0;
}