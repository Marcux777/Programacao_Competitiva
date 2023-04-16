#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int tam = nums.size();
        vector<int> ans(tam);
        for (int i = 0; i < tam; i++)
        {
            ans[(i + k) % tam] = nums[i];
        }
        nums = ans;
    }
};

int main()
{
    Solution s;
    std::vector<int> nums{1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    s.rotate(nums, k);
    for (auto num : nums)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}