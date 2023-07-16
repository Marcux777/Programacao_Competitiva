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
    Solution solution;

    vector<int> nums = {2, 5, 6, 8, 10, 12, 15};
    int target = 8;

    int result = solution.search(nums, target);

    cout << "Índice do elemento encontrado: " << result << endl;

    return 0;
}
