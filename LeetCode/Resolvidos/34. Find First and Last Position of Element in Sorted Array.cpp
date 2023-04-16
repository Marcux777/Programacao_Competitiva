#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int l = menorIndex(nums, target);
        int r = maiorIndex(nums, target);
        return {l, r};
    }

    int menorIndex(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        int pos = -1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
            {
                pos = mid;
                r = mid - 1;
            }
            else
            {
                if (nums[mid] > target)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
        }
        return pos;
    }

    int maiorIndex(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        int pos = -1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
            {
                pos = mid;
                l = mid + 1;
            }
            else
            {
                if (nums[mid] > target)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
        }
        return pos;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> res = s.searchRange(nums, target);
    cout << "[" << res[0] << "," << res[1] << "]" << endl;
    return 0;
}
