#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int lo = 0, hi = nums.size();
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }
        return lo;
    }
};

int main()
{
    Solution s;
    std::vector<int> nums{1, 3, 5, 6};
    int target = 5;
    int pos = s.searchInsert(nums, target);
    std::cout << "O alvo " << target << " deve ser inserido na posicao " << pos << std::endl;
    return 0;
}